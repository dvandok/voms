/* soapStub.h
   Generated by gSOAP 2.7.9k from VOMSAC.h
   Copyright(C) 2000-2007, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#ifndef soapStub_H
#define soapStub_H
#include "stdsoap2.h"
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#ifndef SOAP_TYPE_ns1__StatusCodeType
#define SOAP_TYPE_ns1__StatusCodeType (7)
/* ns1:StatusCodeType */
struct ns1__StatusCodeType
{
	char *Value;	/* optional attribute of type xsd:anyURI */
};
#endif

#ifndef SOAP_TYPE_ns1__StatusType
#define SOAP_TYPE_ns1__StatusType (8)
/* ns1:StatusType */
struct ns1__StatusType
{
	struct ns1__StatusCodeType *ns1__StatusCode;	/* required element of type ns1:StatusCodeType */
	char *ns1__StatusMessage;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE__ns1__GetAttributeCertificate
#define SOAP_TYPE__ns1__GetAttributeCertificate (10)
/* ns1:GetAttributeCertificate */
struct _ns1__GetAttributeCertificate
{
	int __sizeFQAN;	/* sequence of elements <ns1:FQAN> */
	char **ns1__FQAN;	/* optional element of type xsd:string */
	int __sizeTarget;	/* sequence of elements <ns1:Target> */
	char **ns1__Target;	/* optional element of type xsd:string */
	int *ns1__Lifetime;	/* optional element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE__ns1__GetAttributeCertificateResponse
#define SOAP_TYPE__ns1__GetAttributeCertificateResponse (13)
/* ns1:GetAttributeCertificateResponse */
struct _ns1__GetAttributeCertificateResponse
{
	struct ns1__StatusType *Status;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type ns1:StatusType */
	char *AttributeCertificate;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE___ns1__GetAttributeCertificate
#define SOAP_TYPE___ns1__GetAttributeCertificate (18)
/* Operation wrapper: */
struct __ns1__GetAttributeCertificate
{
	struct _ns1__GetAttributeCertificate *ns1__GetAttributeCertificate;	/* optional element of type ns1:GetAttributeCertificate */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (19)
/* SOAP Header: */
struct SOAP_ENV__Header
{
#ifdef WITH_NOEMPTYSTRUCT
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (20)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (22)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
	char *__any;
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (25)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (26)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
	char *faultcode;	/* optional element of type xsd:QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (4)
typedef char *_XML;
#endif

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE_xsd__anyURI
#define SOAP_TYPE_xsd__anyURI (6)
typedef char *xsd__anyURI;
#endif


/******************************************************************************\
 *                                                                            *
 * Typedef Synonyms                                                           *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Service Operations                                                         *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 __ns1__GetAttributeCertificate(struct soap*, struct _ns1__GetAttributeCertificate *ns1__GetAttributeCertificate, struct _ns1__GetAttributeCertificateResponse *ns1__GetAttributeCertificateResponse);

/******************************************************************************\
 *                                                                            *
 * Stubs                                                                      *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetAttributeCertificate(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _ns1__GetAttributeCertificate *ns1__GetAttributeCertificate, struct _ns1__GetAttributeCertificateResponse *ns1__GetAttributeCertificateResponse);

/******************************************************************************\
 *                                                                            *
 * Skeletons                                                                  *
 *                                                                            *
\******************************************************************************/

SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__GetAttributeCertificate(struct soap*);

#ifdef __cplusplus
}
#endif

#endif

/* End of soapStub.h */