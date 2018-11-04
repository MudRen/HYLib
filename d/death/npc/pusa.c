#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
        HIY "�ز�����������������ӷ�\n\n" NOR,
        HIY "�ز����������һֻ�֣��������޹�â��������Ķ���֮�ϡ�\n\n" NOR,
        HIY "�ز���������̾һ��������Ϊ���ŵ��ӣ�ȴҪ������˿��ѣ�ֻ�������ˣ����գ����գ�\n\n" NOR,
        HIY "�ز������������굱һ�������ʮ�����ѣ����ܳ��ѿຣ���ճ�������\n\n" NOR,
        HIY "�ز�������̾������Ի���Ҳ��������˭��������������߰ɣ�ȥ������ǰ������ծ��\n\n"
                HIW"������Լ�����ʶԽ��Խ����������ʡ�����ˡ�����\n\n" NOR,
});

void create()
{
        set_name("�ز�������", ({ "dizangwang pusa", "pusa", "budda" }) );
        set("title",  HIY"�����ֻ���"NOR );
        set("long", "���ͷ���ף��޷��������ı���\n");
        set("attitude", "peaceful");
        set("chat_chance", 5);
        set("chat_msg", ({ 
"���������һ�󣺡������ӷ𡱵�������\n",
"���߽�������������˫�ֺ�ʮ�����ڵ��ϡ�\n",
        }) );
        set("age", 300000);
        set("combat_exp", 200000);
        set("max_jing", 1000);
        set("max_qi", 1000);
        setup();
}

void init()
{
        ::init();
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;
        call_out( "death_stage", 60, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
        int i;
        object *inv;
        if( !ob || !present(ob) ) return;

        if( !ob->is_ghost() ) {
                command("say �ֻ��޳�������֮�ˣ�Ӧ���ص�����ȥ���ǡ�");
                message_vision("������ʿ���˳���������$N��һ�ξͲ����ˣ�\n", ob);
                ob->reincarnate();
                ob->move(REVIVE_ROOM);
                tell_object(ob, HIW"��һ��������������ȴ�����Լ��Ѿ��ص������䣡\n"NOR);
                message("vision","���Ȼ������Ӱ��֪��ʲô�ط�ð�˳�����\n", environment(ob), ob);
                return;
        }

        tell_object(ob, death_msg[stage]);
        if( ++stage < sizeof(death_msg) ) {
                call_out( "death_stage", 5, ob, stage );
                return;
        } else
                ob->reincarnate();
ob->save();
        ob->move(REVIVE_ROOM);
        message("vision","���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);
}
