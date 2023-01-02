#include <stdint.h>


#define   Reg_Enable_RCC     (uint32_t*) 0x40021018 // adresse du registre assurant l'activation des horloges (RCC) des ports A et C
#define   Reg_Config_Led     (uint32_t*) 0x40011004  // adresse du registre de configuration du Port C (reli� aux leds)
#define   Reg_BSRR_Led	     (uint32_t*) 0x40011010  // adresses du registre permettant la mise � 1 des bits du port C
#define   Reg_BRR_Led	     (uint32_t*) 0x40011014 // adresses du registre permettant la mise � 0 des bits du port C

#define   Reg_Config_Bouton  (uint32_t*) 0x40010804// adresse du registre de configuration du port A (reli� au bouton)
#define   Reg_Bouton         (uint32_t*) 0x40010808 //adresse du registre en entr�e (IDR) du port A


 int etat_bouton; // variable permettant de lire l'etat du bouton

int main ()
{


 
 // activer les horloges des ports reli�s aux leds et au bouton
 *Reg_Enable_RCC  = 0x00000014;

 // Configurer les bits reli�s aux leds
 *Reg_Config_Led &= 0xFFFFFF00 ;
	*Reg_Config_Led |= 0x011 ;
 
 // configurer le bit reli� au bouton
 *Reg_Config_Bouton &= 0xFFFFFF00 ; // Input Floating
*Reg_Config_Bouton |= 0x44 ;

//Testet Bouton et allumer si appuy� sinon �teindre

while (1)
{
  etat_bouton = *Reg_Bouton & 0x01; // lire l'etat du bit reli� au bouton (bit PA0)
  
if (etat_bouton == 0x0001) // si appui

{
 *Reg_BSRR_Led = 0x0300;// allumer leds

}
else //sinon

{
  // Eteindre les deux leds.
 *Reg_BRR_Led = 0x0300; 

   }
}
}