// yan.c �����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�����", ({ "yu daiyan", "yu" }));
        set("nickname", "�䵱����");
        set("long",
                "���������������ҵĵ��ӡ��䵱����֮��������ҡ�\n"
                "��һ���ɸɾ������಼������\n"
                "��������ʮ��ͷ��ͣ�˫�Ȳзϣ������������������佣��\n");
        set("gender", "����");
        set("age", 31);
        set("attitude", "peaceful");
        set("class", "swordsman");
        set("shen_type", 1);
        set("str", 28);
        set("int", 30);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 8000);
        set("max_jing", 8000);
        set("neili", 3500);
        set("max_neili", 12500);
        set("jingli", 1000);
        set("max_jingli", 1000);
        set("jiali", 50);
        set("combat_exp", 1550000);
        set("score", 60000);

        set_skill("force", 200);
        set_skill("taiji-shengong", 200);
        set_skill("dodge", 150);
        set_skill("tiyunzong", 250);
        set_skill("unarmed",200);
        set_skill("taiji-quan", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
set_skill("claw", 150);
set_skill("strike", 150);
	set_skill("hand", 180);
	set_skill("paiyun-shou", 180);
	set_skill("shenmen-jian", 180);
	set_skill("yitian-zhang", 180);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "paiyun-shou");
        map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
//prepare_skill("hand", "paiyun-shou");
//prepare_skill("strike", "yitian-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),                
        }) );
	set("chat_chance", 1);

        set("chat_msg", ({
            "�����˵�������佣���Ƕ�ʦ����Ѫ��",
            "���������̾������λ��ʦ���κ��ҵ��ȣ���Ҳ��Ѽׯһ�١�"
        }));

         create_family("�䵱��", 2, "����");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/bluecloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",3 , ob);
        }
}

void greeting(object ob)
{
   int i;
   if (environment(ob)->query("short")=="���ҹ���̨"){
if (!ob) return;
   if (((int)ob->query_skill("taiji-shengong", 1) == 0))
   {
      message_vision(CYN"ʮ�����Ӷ�$N�����ȵ��������аħ������������佣��\n\n"NOR,ob);
      ob->set("qi",30);
//      if ((int)ob->query("combat_exp") <2000) ob->set("combat_exp",1);
//         else ob->add("combat_exp",-1000);
      message_vision(CYN"���佣���ʱ��������̨�Ͻ����ݺᣬ��$NΧ�����롣\n"NOR,ob);
      message_vision(CYN"ʮ���ڳ����������$N���ϻ�����ʮ�������ӣ���Ѫ���졣\n"NOR,ob);
      say(CYN"\n\n���������ŭ�ݣ���аħ�����Ҳ�Ҵ����佣�󣡡�\n");
      message_vision("����ҾӸ����£�����һ�ư�$N�����̨��\n\n\n"NOR,ob);
      ob->unconcious();
      ob->move("/d/wudang/nanyangong");
      CHANNEL_D->do_channel(this_object(),"chat",sprintf("%s ˽�����佣������ɳ����ף�����һ����",ob->name(1)));
   }
}
}

void attempt_apprentice(object me)
{
        if ((int)me->query("guarded") < 3) {
                command("say " + RANK_D->query_respect(me) +
                        "������䵱�ɾ��˶����������м��������أ�");
                return;
        }
        if ((int)me->query_skill("taiji-shengong", 1) < 30) {
                command("say ���䵱�����ڼ��书���������ڹ��ķ���");
                command("say " + RANK_D->query_respect(me) +
                        "�Ƿ�Ӧ����̫�����϶��µ㹦��");
                return;
        }
        if ((int)me->query("shen") < 1000) {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(me) +
                        "�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + me->query("id"));
}
