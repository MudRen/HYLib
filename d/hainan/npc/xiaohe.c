#include <ansi.h>;
inherit NPC;

void create()
{
        set_name(HIW"�ɺ�"NOR, ({ "xian he", "he" }) );
        set("race", "Ұ��");
        set("age", 100);
        set("long", "һֻ���������ɺף������������(qi)��ȥ.\n");
        set("attitude", "peaceful");
        set("spi",100);
        set("int",100);
        set("per",100);
        set("con",100);
        set("limbs", ({ "ͷ��", "����", "���" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 50000000);

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 110);
        set_temp("apply/armor", 110);
        set_temp("apply/defence",90);

        setup();
}
void die()
{
        object ob,me;
me = this_player();
        message_vision("$N˻�ƵĽ��˼��������ڵ������ˡ�����\n һ���׹�������һ����������ëƮ����$N�����ϡ���\n\n", this_object(),me);
        ob = new("/d/hainan/obj/yumao");
        ob->move(me);
        destruct(this_object());
}
void init()
{
        add_action("do_xia","xia");
        add_action("do_qi","qi");

}
int do_qi(string arg)
{
        object me;
        int extra;
        me = this_player();
        if (arg = "�ɺ�" && arg = "xian he" && arg = "he")
        {
                extra = me->query_skill("dodge",1);
                if (extra < 100) return notify_fail("����Ṧ������������\n");
                if (me->query_temp("mark/qi1")) return notify_fail("�㻹Ҫ�ﵽ�ɺ��Դ���ȥ��\n");
                message_vision(HIW"ֻ��$N����Ծ�����ɺ׵ĺ󱳣��ɺ�����$N��������ա�����\n\n\n"NOR,me);
                set("long","һֻ���������ɺף��и���������������.\n");
                me->set_temp("mark/qi1",1);
                me->set_temp("mark/tiankong",1);
                me->move("/d/hainan/kongzhong");
                this_object()->move("/d/hainan/kongzhong");
                return 1;
        }
}

int do_xia(string arg)
{
        object me;
        me = this_player();
        if (arg != "�ɺ�" && arg != "xian he" && arg != "he") 
                return notify_fail("��Ҫ����ȥ��\n");
        if (!me->query_temp("mark/qi1")) return notify_fail("��Ҫ���ģ�������\n");
        if (me->query_temp("mark/tiankong"))
        {
                message_vision(HIR"$N�������ɺף������Ŵӿ��е�����ȥ��.....\n\n\n"NOR,me);
                me->die();
                message("channel:rumor",YEL"��ҥ�ԡ�ĳ�ˣ��������ѣ�����һ�ˣ�\n"NOR,users());
                destruct(this_object());
        }
        else
        {
                message_vision("ֻ��$N����һԾ���������ɺס�\n",me);
                set("long","һֻ���������ɺף������������(qi)��ȥ.\n");
                me->delete_temp("mark/qi1",);
        }
        return 1;
}
