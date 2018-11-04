#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
        HIW "����˵����Ŷ�������˸��µģ����ʲô���֣�\n\n" NOR,
        HIW "����˵������������������������ȥͶ̥�ɡ�\n\n" NOR,
        HIW "�����������ͷ������ȥ����ζ���������̣������������£��������̡�\n\n" NOR,
        HIW "һ�����룬���������������������ǰ�����ж�Թ���ޣ��Ծ������ǡ�\n\n" NOR,
        HIW "����˵�������Ѿ�����������ȥ�ɣ���ȴ��جǰ������̥������\n\n"
                "���Ժ����У�������Լ��ֶ����˹����ֻء�����\n\n" NOR,
});

void create()
{
        set_name("����", ({ "meng po", "meng", "po" }) );
        set("long","������һ����ò��ɭ���ϸ����ƹ�������ϵ�����ͤ��\n");
        set("attitude", "peaceful");
        set("chat_chance", 5);
        set("chat_msg", ({
"���źٺ�һЦ�����ɣ����ɣ��ȿ���������������ȴǰ���ɡ�\n",
"����ת���ó�һ�����룬����Ҩ��һ�����̵���������\n"
        }) );
        set("age", 2107);
        set("combat_exp", 20000);
        set("max_jing", 900);
        set("max_qi", 900);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        setup();
}

void init()
{
        ::init();        
        if( !previous_object()
           || !userp(previous_object()) ) 
            return;
        call_out( "death_stage", 60, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
        int i;
        object *inv;
        if( !ob || !present(ob) ) return;

        if( !ob->is_ghost() ) {
                command("say �ף�����ô���˸����ˣ�");
                message_vision("��֪������ð���������޳�������$N��һ�ξͲ����ˣ�\n", ob);
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

        inv =  all_inventory(ob);
ob->move(REVIVE_ROOM);
ob->save();
        message("vision","���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);

}

