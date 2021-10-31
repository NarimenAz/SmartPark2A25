--------------------------------------------------------
--  Fichier cr�� - dimanche-octobre-31-2021   
--------------------------------------------------------
DROP TABLE "SYSTEM"."PRODUIT" cascade constraints;
--------------------------------------------------------
--  DDL for Table PRODUIT
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."PRODUIT" 
   (	"REF" VARCHAR2(20 BYTE), 
	"NOM" VARCHAR2(20 BYTE), 
	"CATEGORIE" VARCHAR2(20 BYTE), 
	"QUANTITE" NUMBER, 
	"PRIX" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into SYSTEM.PRODUIT
SET DEFINE OFF;
--------------------------------------------------------
--  DDL for Index PRODUIT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "SYSTEM"."PRODUIT_PK" ON "SYSTEM"."PRODUIT" ("REF") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table PRODUIT
--------------------------------------------------------

  ALTER TABLE "SYSTEM"."PRODUIT" ADD CONSTRAINT "PRODUIT_PK" PRIMARY KEY ("REF")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "SYSTEM"."PRODUIT" MODIFY ("PRIX" NOT NULL ENABLE);
  ALTER TABLE "SYSTEM"."PRODUIT" MODIFY ("QUANTITE" NOT NULL ENABLE);
  ALTER TABLE "SYSTEM"."PRODUIT" MODIFY ("CATEGORIE" NOT NULL ENABLE);
  ALTER TABLE "SYSTEM"."PRODUIT" MODIFY ("NOM" NOT NULL ENABLE);
  ALTER TABLE "SYSTEM"."PRODUIT" MODIFY ("REF" NOT NULL ENABLE);
