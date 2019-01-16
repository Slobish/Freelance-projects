/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.Slobish;

/**
 *
 * @author Franco
 */
public class GlobalSession {
    
    public static String username=null;
    public static String password=null;
    
    
    GlobalSession(String LoginUsername, String LoginPassword)
    {
        GlobalSession.username=LoginUsername;
        GlobalSession.password=LoginPassword;
    }
    GlobalSession()
    {
        
    }

}
