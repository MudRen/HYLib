#include <ansi.h>
#include <armor.h>


inherit ARMOR;

void create()
{
        set_name(HIR "��������" NOR, ({ "longxiang jiasha", "longxiang", "jiasha" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIR "����һ���¾ɵ����ģ�ͨ��Ѫ�죬ӡ��������������"
                            "�ִ�����\n�ޱȣ�������ɽ��˿�켰ѩ��˿��֯���ɡ�"
                            "���д���˵����\n��������������Ǽ������������֮"
                            "�ϡ�\n" NOR);
                set("value", 8000);
                set("treasure", 1);
                set("material", "cloth");
                set("wear_msg", HIY "$N" HIY "չ��$n" HIY "����ʱ����ת�����"
                                "����ȫ��\n" NOR);
                set("armor_prop/armor", 900);
                set("force", 13);
                set("stable", 100);
        }
        setup();
}


