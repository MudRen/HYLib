//yellow-rose.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name(HIR "999���õ��" NOR, ({ "red flower", "rose","flower" }) );
       set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("long", HIR "999�使�����εĺ�õ�塣\n" NOR);
                set("unit", "��");
               set("value", 1000);
                set("material", "plant");
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");
                set("female_only", 1);

        }
        setup();
}
