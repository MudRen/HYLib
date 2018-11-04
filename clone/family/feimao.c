// feimao.c ��ë�ȵ���

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(WHT "��ë�ȵ���" NOR, ({ "missile" }));
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "����һö�г̷ɵ����۸���ˣ�"
                            "�����ڷ�չ����ʿ����\n");
                set("value", 2000000);
                set("no_sell", 1);
                set("unit", "ö");
	}
}

void init()
{
        add_action("do_launch", "launch");
        add_action("do_aim", "aim");
}

int do_launch(string arg)
{
        object me;
        object ob;
        string user;

        me = this_player();

        if (me->is_busy())
                return notify_fail("ʲô���鶼����æ������˵��\n");

        if (me->is_fighting())
                return notify_fail("������ٿ�����Щ����ɣ�\n");

        if (! arg || ! id(arg))
                return notify_fail("��Ҫ����ʲô��\n");

        if (! stringp(user = query_temp("aim")))
                return notify_fail("������׼(aim)���ٷ��䣡\n");

        if (! objectp(ob = find_player(user)) ||
	    ! me->visible(ob))
                return notify_fail("��Ҫը��������ں��������ϡ�\n");

        message_vision(HIM "$N�ͳ�һ��" + name() + HIM "���ȵ���"
                       "����ë��׼�����䣡��˵��һ�����أ�\n"
                       "�������䡱��һ����" + name() + HIM "����ƨ�ɲ����ˣ�\n" NOR, me);

        message_vision(HIC "ͻȻ��մ���һ���Х������...\n" +
                       "���䡱��һ����$N" HIC "��ը�÷������ף������ڵأ�"
                       "һ�仰��˵������...\n" NOR, ob);

        if (wizardp(ob))
                message_vision(HIM "$N" HIM "��æ��ȼһ�ŷ�ֽ������"
                       "ֱ��߶����̫���Ͼ�������...��\n" NOR, ob);
        else
        {
                message_vision(HIG "$N" HIG "һ���޹��ı��飬��ԩ������\n" NOR, ob);
                ob->ban_say_until(60, "�����ڱ�ը��ͷ���ۻ���˵������");
                CHANNEL_D->do_channel(this_object(), "rumor",
                                      "��˵" + ob->name(1) +
                                      "����������ë�ȵ���Ϯ�������ھ���ʧ����");
        }

        destruct(this_object());
        return 1;
}

int do_aim(string arg)
{
        object me;
        object ob;
        string my_id;

        if (arg && sscanf(arg, "%s with %s", arg, my_id) == 2 && ! id(my_id))
                return notify_fail("����û��(" + my_id + ")����������\n");

        if ((arg == "none" || arg == "cancel") && query_temp("aim"))
        {
                delete_temp("aim");
                write("����ȡ���ɵ���׼��\n");
                return 1;
        }

        me = this_player();

        if (! arg || ! objectp(ob = find_player(arg)) ||
	    ! me->visible(ob))
                return notify_fail("��Ҫ��׼�ĸ���ң�\n");

        if (me->is_busy())
                return notify_fail("ʲô���鶼����æ������˵��\n");

        if (me->is_fighting())
                return notify_fail("������ٿ�����Щ����ɣ�\n");

        if (me->ban_say())
                return notify_fail("������˵��������...����Ҳû�����䡣\n");

        tell_object(me, HIY "���ͳ�һ��" + name() + HIY "�������飬�����顣\n" NOR, me);
        message("vision", HIR "���۲����ǡ��������棬" + ob->name(1) +
                          HIR "�Ѿ�������" + name() +
                          HIR "��׼�ˡ�\n" NOR, ob);

        set_temp("aim", ob->query("id"));
        me->start_busy(2);

        return 1;
}

string long()
{
        object ob;
        string msg;

        msg = query("long");
        if (query_temp("aim") &&
            objectp(ob = find_player(query_temp("aim"))))
        {
                msg += "������ö�ɵ�����׼��" + ob->name(1) +
                       "����������(launch)��\n";
        } else
                msg += "������ö�ɵ�������׼��״̬��"
                       "������ʱ��׼(aim)��\n";
        return msg;
}
