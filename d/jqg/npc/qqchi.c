// qqchi.c ��ǧ��
// By River 99.5.25
#include <ansi.h>
inherit NPC;
string ask_dan();
void create()
{
        set_name("��ǧ��", ({ "qiu qianchi", "qiu", "qianchi"}));
        set("nickname", HIY"��������"NOR);
        set("title",HIW"�����Ů����"NOR);
        set("long","һ����������ͺͷ������ϥ���ڵ��£�����ŭ�ݣ���Ȼ������\n"); 
        set("gender", "Ů��");
        set("age", 55);
        set("attitude", "friendly");

        set("unique", 1);
        set("shen_type", -20);
        set("str", 35);
        set("int", 30);
        set("con", 28);
        set("dex", 5);
        set("per", 8);

        set("max_qi", 6000);
        set("max_jing", 6000);
        set("neili",9500);
        set("max_neili", 9500);
        set("eff_jingli",2000);
        set("jiali", 40);
        set("combat_exp", 900000);
        set("score", 2000);

        set_skill("force", 230);
        set_skill("guiyuan-tunafa", 230);
        set_skill("dodge", 230);
        set_skill("shuishangpiao", 230);
        set_skill("strike", 230);
        set_skill("tiezhang-zhangfa", 230);
        set_skill("parry", 230);
        set_skill("literate", 100);

        map_skill("force", "guiyuan-tunafa");
        map_skill("dodge", "shuishangpiao");
        map_skill("strike", "tiezhang-zhangfa");
        map_skill("parry", "tiezhang-zhangfa");
        prepare_skill("strike", "tiezhang-zhangfa");

        set("inquiry", ([ 
               "���鵤" : (: ask_dan :),
               "����ֹ" : "�ߣ���������ҵ���˵ز�����ɱ��������ǧ���Ĳ�Ϊ�ˡ�", 
        ]));
        setup();
}

void kill_ob(object me,object weapon,object ob)
{
        me=this_player();
        weapon = me->query_temp("weapon");
        ob=this_object();
        command("sneer " + me->query("id"));
        if( weapon ){
          message_vision(HIW"\n$NͻȻ����һ�������зɳ�һ�� ���һ�죬����$n�������յ��Ǳ�"+weapon->name()+HIW"���ϡ�\n"NOR,ob,me);
          weapon->move(environment(ob));
          me->start_busy(2);
          message_vision(HIR"\n$Nֻ���ֱ۾�����ָ��Ȼ����ס������һ����"+weapon->name()+HIR"���ڵ��¡�\n"NOR,me);
          }
        else {
          message_vision(HIW"\n$N������˶��Ѽ���������ƿ�֮�������Х��ֱָ$nС����ȥ�Ƶ����Ǻ������ס�\n"NOR,ob,me);
          me->start_busy(2);
          message_vision(HIR"\n$N��������һ���߽У�����������������ȥ��\n"NOR,me);
          me->set("eff_qi", me->query("eff_qi")/2);
          me->set("qi",me->query("eff_qi"));
          }
         if(!ob->is_killing(me->query("id")))
          ::kill_ob(me);
}

string ask_dan()
{
         if(this_player()->query_temp("jqg/chi"))
             return "��λ"+RANK_D->query_respect(this_player())+"���Ҳ����Ѿ������㣬���鵤����֮����ô��";
          this_player()->set_temp("jqg/chi", 1);
          return "�����ڴ�����������Ե�������Ψһһ�ž��鵤�Ҳ��ڴ����������ש�¡�";
}
