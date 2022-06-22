package com.example.listas2;

import java.util.Date;

public final class NuevaEntrada {
    private final String titulo;
    private final String autor;
    private final Date fecha;
    private final int icono;

    public NuevaEntrada(final String t, final String a, final Date f, final int i) {
        this.titulo = t;
        this.autor = a;
        this.fecha = f;
        this.icono = i;
    }
    public String getTitulo() {
        return titulo;
    }
    public String getAutor() {
        return autor;
    }
    public Date getFecha() {
        return fecha;
    }
    public int getIcono() {
        return icono;
    }
}