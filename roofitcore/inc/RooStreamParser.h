/*****************************************************************************
 * Project: RooFit                                                           *
 * Package: RooFitCore                                                       *
 *    File: $Id: RooStreamParser.rdl,v 1.16 2005/06/21 19:59:52 wverkerke Exp $
 * Authors:                                                                  *
 *   WV, Wouter Verkerke, UC Santa Barbara, verkerke@slac.stanford.edu       *
 *   DK, David Kirkby,    UC Irvine,         dkirkby@uci.edu                 *
 *                                                                           *
 * Copyright (c) 2000-2005, Regents of the University of California          *
 *                          and Stanford University. All rights reserved.    *
 *                                                                           *
 * Redistribution and use in source and binary forms,                        *
 * with or without modification, are permitted according to the terms        *
 * listed in LICENSE (http://roofit.sourceforge.net/license.txt)             *
 *****************************************************************************/
#ifndef ROO_STREAM_PARSER
#define ROO_STREAM_PARSER

#include "Riostream.h"
#include "TString.h"

class RooStreamParser {
public:
  // Constructors, assignment etc.
  RooStreamParser(istream& is) ;
  RooStreamParser(istream& is, const TString& errPrefix) ;
  virtual ~RooStreamParser();

  TString readToken() ;
  TString readLine() ;
  Bool_t expectToken(const TString& expected, Bool_t zapOnError=kFALSE) ;
  void setPunctuation(const TString& punct) ;
  TString getPunctuation() const { return _punct ; }

  Bool_t readDouble(Double_t& value, Bool_t zapOnError=kFALSE) ;
  Bool_t convertToDouble(const TString& token, Double_t& value) ;

  Bool_t readInteger(Int_t& value, Bool_t zapOnError=kFALSE) ;
  Bool_t convertToInteger(const TString& token, Int_t& value) ;

  Bool_t readString(TString& value, Bool_t zapOnError=kFALSE) ;
  Bool_t convertToString(const TString& token, TString& string) ;

  inline Bool_t atEOL() { Int_t nc(_is.peek()) ; return (nc=='\n'||nc==-1) ; }
  inline Bool_t atEOF() { return _atEOF ; }
  void zapToEnd(Bool_t inclContLines=kFALSE) ;

  Bool_t isPunctChar(char c) const ;
  
protected:

  istream& _is ;
  Bool_t _atEOL ;
  Bool_t _atEOF ;
  TString _prefix ;
  TString _punct ;

  
  ClassDef(RooStreamParser,0) // Utility class that parses istream data into tokens
};

#endif
