#include <ansi.h>
#include <armor.h>
inherit ARMOR; 
void create() {
        set_name("��³", ({ "tibetan skirt","skirt" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("value", 400);
                set("armor_prop/armor", 10);
                set("long","һ�ֲ���С���䡱��Χȹ���ǲ��帾Ůϲ�������Ҳ�ǲ��帾Ů�ı�־��\n");
        }

}  
