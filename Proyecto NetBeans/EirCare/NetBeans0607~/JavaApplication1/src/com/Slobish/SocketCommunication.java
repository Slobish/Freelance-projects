/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.Slobish;
import java.net.*;
import java.io.*;
/**
 *
 * @author Maq301
 */
public class SocketCommunication {
    
    int PUERTO;
    ServerSocket sc;
    Socket so;
    DataOutputStream salida;
    String mensajeRecibido;
    String mensajeEnviar;
    public void initServer()
    {
        BufferedReader entrada;
        
        try
        {
            sc= new ServerSocket(PUERTO);
            so=new Socket();
            System.out.println("esperando una conexion");
            so=sc.accept();
            System.out.println("Un cliente se ha conectado.");
            entrada = new BufferedReader(new InputStreamReader(so.getInputStream()));
            salida = new DataOutputStream(so.getOutputStream());
            System.out.println("Confirmando conexion al cliente");
            salida.writeUTF("conexion exitosa");
            mensajeRecibido=entrada.readLine();
            System.out.println(mensajeRecibido);
            sc.close();
            
        }
        catch (IOException e)
        {
            System.out.println("Error"+e.getMessage());
        }
        
    }
    
    SocketCommunication ( int PUERTO)
    {
        this.PUERTO=PUERTO;
    }
  
}
