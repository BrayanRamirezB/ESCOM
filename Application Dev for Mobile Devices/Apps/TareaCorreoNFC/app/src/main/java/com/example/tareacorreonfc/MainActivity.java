package com.example.tareacorreonfc;

import androidx.appcompat.app.AppCompatActivity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.PendingIntent;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.net.Uri;
import android.nfc.NdefMessage;
import android.nfc.NdefRecord;
import android.nfc.NfcAdapter;
import android.nfc.NfcManager;
import android.nfc.Tag;
import android.nfc.tech.Ndef;
import android.nfc.tech.NdefFormatable;
import android.os.Parcelable;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.nio.charset.Charset;
import java.util.Arrays;

public class MainActivity extends AppCompatActivity {
    private static final int DIALOG_WRITE_URL = 1;
    private static final int DIALOG_NEW_TAG = 3;
    private static final String ARG_MESSAGE = "message";
    private EditText myUrl;
    private Button myWriteUrlButton;
    private boolean writeUrl = false;
    private AlertDialog.Builder builder;
    private static final int PENDING_INTENT_TECH_DISCOVERED = 1;
    private NfcAdapter mNfcAdapter;
    String correo;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        myUrl = findViewById(R.id.myUrl);
        myWriteUrlButton = findViewById(R.id.myWriteUrlButton);
        myWriteUrlButton.setOnClickListener(new View.OnClickListener() {

            public void onClick(View view) {
                writeUrl = true;
                //ShowDialog(DIALOG_WRITE_URL);
                MainActivity.this.showDialog(DIALOG_WRITE_URL);
            }
        });
    }

    protected Dialog onCreateDialog(int id, Bundle args) {
        switch (id) {
            case DIALOG_WRITE_URL:
                return new AlertDialog.Builder(this).setTitle("Ingresa un correo")
                        .setMessage("Toca la etiqueta para escribir")
                        .setCancelable(true)
                        .setNeutralButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int which) {
                                dialog.cancel();
                            }
                        })
                        .setOnCancelListener(new DialogInterface.OnCancelListener() {

                            public void onCancel(DialogInterface dialogInterface) {
                                writeUrl = false;
                            }
                        }).create();

            case DIALOG_NEW_TAG:
                return new AlertDialog.Builder(this).setTitle("Etiqueta detectada ")
                        .setCancelable(true)
                        .setNeutralButton(android.R.string.ok, new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int which) {
                                dialog.dismiss();
                            }
                        }).create();
        }
        return null;
    }

    protected void onPrepareDialog(int id, Dialog dialog, Bundle args) {
        switch (id) {
            case DIALOG_NEW_TAG:
                String message = args.getString(ARG_MESSAGE);
                if (message != null) ((AlertDialog) dialog).setMessage(message);
                break;
        }
    }

    public void onResume() {
        super.onResume();

        NfcManager nfcManager = (NfcManager) this.getSystemService(Context.NFC_SERVICE);
        mNfcAdapter = nfcManager.getDefaultAdapter();

        PendingIntent pi = createPendingResult(PENDING_INTENT_TECH_DISCOVERED, new Intent(), 0);
        mNfcAdapter.enableForegroundDispatch(
                this,
                pi,
                new IntentFilter[]{new IntentFilter((NfcAdapter.ACTION_TECH_DISCOVERED))},
                new String[][]{
                        new String[]{"android.nfc.tech.NdefFormatable"},
                        new String[]{"android.nfc.tech.Ndef"}
                }
        );
    }

    public void onPause() {
        super.onPause();
        mNfcAdapter.disableForegroundDispatch(this);
    }

    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        switch (requestCode) {
            case PENDING_INTENT_TECH_DISCOVERED:
                resolveIntent(data, true);
                break;
        }
    }

    private void resolveIntent(Intent data, boolean foregroundDispatch) {
        String action = data.getAction();
        if (NfcAdapter.ACTION_TECH_DISCOVERED.equals(action)) {

            Tag tag = data.getParcelableExtra(NfcAdapter.EXTRA_TAG);

            if (foregroundDispatch && writeUrl) {

                writeUrl = false;

                String urlStr = myUrl.getText().toString();
                byte[] urlBytes = urlStr.getBytes(Charset.forName("UTF-8"));
                byte[] urlPayload = new byte[urlBytes.length + 1];
                urlPayload[0] = 0;
                System.arraycopy(urlBytes, 0, urlPayload, 1, urlBytes.length);
                NdefRecord urlRecord = new NdefRecord(NdefRecord.TNF_WELL_KNOWN,
                        NdefRecord.RTD_URI,
                        new byte[0],
                        urlPayload);

                NdefMessage msg = new NdefMessage(new NdefRecord[]{urlRecord});
                Ndef ndefTag = Ndef.get(tag);

                if (ndefTag != null) {
                    try {
                        ndefTag.connect();
                        ndefTag.writeNdefMessage(msg);

                    } catch (Exception e) {
                    } finally {
                        try {
                            ndefTag.close();
                        } catch (Exception e) {
                        }
                    }
                } else {
                    NdefFormatable ndefFormatableTag = NdefFormatable.get(tag);
                    if (ndefFormatableTag != null) {
                        try {
                            ndefFormatableTag.connect();
                            ndefFormatableTag.format(msg);
                        } catch (Exception e) {
                        } finally {
                            try {
                                ndefFormatableTag.close();
                            } catch (Exception e) {
                            }
                        }
                    }
                }
            } else {
                StringBuilder tagInfo = new StringBuilder();
                byte[] uid = tag.getId();
                tagInfo.append("UUID: ")
                        .append(toHexString(uid))
                        .append("\n\n");
                Parcelable[] ndefRaw = data.getParcelableArrayExtra(NfcAdapter.EXTRA_NDEF_MESSAGES);
                NdefMessage[] ndefMsgs = null;
                if (ndefRaw != null) {
                    ndefMsgs = new NdefMessage[ndefRaw.length];
                    for (int i = 0; i < ndefMsgs.length; i++) {
                        ndefMsgs[i] = (NdefMessage) ndefRaw[i];
                    }
                }
                if (ndefMsgs != null) {
                    for (int i = 0; i < ndefMsgs.length; i++) {
                        NdefRecord[] records = ndefMsgs[i].getRecords();
                        if (records != null) {
                            for (int j = 0; j < records.length; j++) {
                                if ((records[j].getTnf() == NdefRecord.TNF_WELL_KNOWN) && Arrays.equals(records[j].getType(), NdefRecord.RTD_URI)) {
                                    byte[] payload = records[j].getPayload();
                                    String uri = new String(Arrays.copyOfRange(payload, 1, payload.length), Charset.forName("UTF-8"));
                                    tagInfo.append("URI: ").append(uri).append("\n");
                                    correo = uri;
                                }
                            }
                        }
                    }
                }
                Bundle args = new Bundle();
                args.putString(ARG_MESSAGE, tagInfo.toString());

                //Código cuando toque una etiqueta

                String[] TO = {correo};
                String[] CC = {""};
                Intent emailIntent = new Intent(Intent.ACTION_SEND);
                emailIntent.setData(Uri.parse("mailto:"));
                emailIntent.setType("text/plain");
                emailIntent.putExtra(Intent.EXTRA_EMAIL, TO);
                emailIntent.putExtra(Intent.EXTRA_CC, CC);
                emailIntent.putExtra(Intent.EXTRA_SUBJECT, "De ESCOM");
                emailIntent.putExtra(Intent.EXTRA_TEXT, "Correo desde Android Studio");
                try {
                    startActivity(Intent.createChooser(emailIntent, "Send mail..."));
                    finish();
                    Log.i("Fin envío de correo...", ""); // Máximo 23 caracteres
                } catch (android.content.ActivityNotFoundException ex) {
                    Toast.makeText(MainActivity.this, "No hay cliente de correo instalado.",
                            Toast.LENGTH_SHORT).show();
                }

                Toast toast = Toast.makeText(MainActivity.this, "Correo enviado a: "+correo, Toast.LENGTH_LONG);
                toast.show();
                //showDialog(DIALOG_NEW_TAG, args);
            }

        }
    }

    public static String toHexString(byte[] bytes) {
        char[] hexArray = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        char[] hexChars = new char[bytes.length * 2];
        int v;
        for (int j = 0; j < bytes.length; j++) {
            v = bytes[j] & 0xFF;
            hexChars[j * 2] = hexArray[v / 16];
            hexChars[j * 2 + 1] = hexArray[v % 16];
        }
        return new String(hexChars);
    }
}