// dingxie.c

#include <armor.h> 
 
inherit BOOTS; 
 
void create() 
{ 
        set_name("��Ь", ({ "ding xie", "shoe" , "dingxie"}) ); 
        set_weight(2000); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "˫"); 
                set("long", "�ʵ��õĹ��ߣ�Ь�ױ鲼������С���Է�ֹ�򻬡�\n"); 
                set("value", 50); 
                set("material", "iron"); 
                set("armor_prop/armor", 3);
		set("armor_prop/dodge", -5);
              } 
        setup(); 
} 
