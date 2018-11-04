#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(NOR + WHT "�ɲ�" NOR, ({ "gan chai", "gan", "chai" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
        	set("unit", "��");
        	set("long", WHT "����һ��ľ��\n" NOR);
        	set("value", 10);
                set("material", "wood");
        }
}

int fire(object me, object ob)
{
        object fire;

        if (environment()->query_temp("warm") >= 40)
                return notify_fail("�����Ѿ����ȵ��ˣ��㻹�ǻ���"
                                   "�ط����ɡ�\n");

        message_vision("$N��" + ob->name() + "��ȼ��" + name() +
                       "��һƬ���Ļ��ӳ�������ܡ�\n", me);

        fire = new(__DIR__"needfire");
        fire->move(environment(me));

        destruct(this_object());
        return 1;
}
