// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// tongjia.c
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("��ͭ��", ({"bronze armor","tongjia","jia","armor"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
       set("long", "һ����Ӳӵ���ͭ�ס�\n");
                set("value", 2200);
                set("material", "steel");
                set("armor_prop/armor", 35);
     set("armor_prop/dodge", -15);
             }
         setup();
}
