// jingang-zhao.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"�����"NOR, ({ "jingang zhao", "zhao" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��������������ģ�ͨ������ɽѩ��˿֯�ɣ������ޱ�
���������ˡ�������������ǰ�ɴ�Ħ����Я����ԭ��аħ��֮���ף�
���Ƿ�����Ͻ�ħ������\n");
                set("material", "silk");
                set("unit", "��");
                set("value", 1000000);
            set("treasure", 1);
                set("wear_msg", HIY "ֻ����������һ����$Nչ��һ����������������������ϡ�
˲ʱ������Ϊ֮ʧɫ������ǧ�������ƶ�䣬һ��ׯ������\n" NOR);
                set("remove_msg", HIY "$N������ִ����������������۵���СС��һ�š�\n" NOR);
                set("armor_prop/armor", 200);
        }
        setup();
}

