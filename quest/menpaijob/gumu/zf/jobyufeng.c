// yufeng.c //���
// By Lgg,1998.9

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW "�������" NOR, ({"yu feng","feng","bee"}) );
        set("race", "Ұ��");
        set("age", 8);
        set("long", "����һֻ��ɫ���۷䣬��ͷ����ͨ�۷��ö࣬\n"
                    "����ϱ����ü�������֡�\n");

        set("str", 40);
        set("dex", 100);

        set("limbs", ({ "ͷ��", "����", "���", "β��" }) );
        set("verbs", ({ "bite", "poke" }) );

set("eff_qi",500);
set("eff_jing",500);
set("max_qi",500);
set("max_jing",500);
        set_temp("apply/attack", 100);
        set_temp("apply/armor", 100);
        set("specitem",1);
        set("no_touxi",1);
        set("no_drop",1);
        set("jobfeng",1);
        set("chat_chance", 5);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
        "�������ͷ��ת��һȦ���ƺ������ⲻ�ǿɲ��۵ĵط����������˵ط����ˡ�\n",
        "���Χ�����ʻ��ɷ�ͣͣ���ƺ�Ҳ�������ڲ����ϡ�\n",
         }) );
//        set("chat_chance_combat", 20);
//        set("chat_msg_combat", ({
//           (: random_move :),
//        }) );

        setup();
}
void init( )
{
        call_out("hunting",400);
}

void hunting()
{
object ob=this_object();
if (this_player())
{
message("vision", HIW"�������ͷ��ת��һȦ���ƺ������ⲻ�ǿɲ��۵ĵط����������˵ط����ˡ���\n"NOR, this_player());
}
destruct(ob);
}
void die()
{
    unconcious();
}
