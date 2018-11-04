//tonbaixiong.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void greeting(object);
void init();
void create()
{
	set_name("ͯ����", ({ "tongbai xiong","xiong"}) );
	set("gender", "����" );
	set("age", 75);
	set("title", HIC"������̷����ó���"NOR);
	set("long", "���׷���ɢ, �������, ���ϵļ���ǣ��, \n"
                    "Բ��˫��, ���ϵ���Ѫ��Ȼ����, �������ǿɲ���\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 11000);
	set("max_jing",11000);
	set("neili", 12000);
	set("max_neili", 12000);
	set("jiali", 200);
	set("combat_exp", 950000);
	set("score", 30000);

          set_skill("sword", 100);
          set_skill("parry", 100);
        set_skill("literate",100);
          set_skill("dodge", 100);
          set_skill("unarmed", 100);
          set_skill("whip", 100);
          set_skill("force", 100);
        set_skill("staff", 100);
          set_skill("strike",100);
         set_skill("blade", 100);

         set_skill("tmjian", 150);
         set_skill("tmzhang", 250);
         set_skill("tmdao", 150);
         set_skill("pmshenfa", 150);
         set_skill("tmdafa", 350);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
set_skill("tmquan", 280);
        map_skill("strike", "tmzhang");
        map_skill("cuff", "tmquan");
  prepare_skill("cuff","tmquan");

prepare_skill("strike","tmzhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.diansha" :),
                (: perform_action, "sword.xuan" :),
                (: perform_action, "sword.tmbiao" :),
                	(: perform_action, "sword.jianshen" :),
                		(: perform_action, "sword.moshen" :),
                (: perform_action, "blade.moxiao" :),
                (: perform_action, "blade.tiandirenmo" :),
                (: perform_action, "blade.xuan" :),                	
                (: perform_action, "blade.yueshen" :),                	
                (: perform_action, "strike.huashen" :),                
                (: perform_action, "strike.zhen" :),                
                (: perform_action, "strike.tmduan" :),                
                (: perform_action, "cuff.tianmo" :),                
                (: perform_action, "cuff.dimo" :),                
                (: perform_action, "cuff.renmo" :),

        }) );

	create_family("�������",2,"���� �����ó���");

	set("chat_chance", 3);
	set("chat_msg", ({
		 "ͯ����ŭ��˫�۵�: ����û��, ��û���ѽ�! �����ֵ��㲻��ԩ����ѽ! ��\n",
	         "ͯ����̾��һ����˵�����ҺͶ����ֵܳ�������, �������ѵ�ʱ��, ���ǻ�û��������!��\n"
        }) );
	setup();
        carry_object(__DIR__"obj/zijinchui");
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/card1")->wear();

}



void attempt_apprentice(object ob)
{
         if (ob->query_int() < 20) {
              command("say " + RANK_D->query_respect(ob) +
                        "�߿��߿����Ҳ����ɵ��˵����");
                return;
        }
         if (ob->query_dex() < 20) {
                command("say " + RANK_D->query_respect(ob) +
                        "���ֲ��ݣ����������ʦ�ɡ�");
                return;
        }
        if ((int)ob->query("shen") > -10000) {
                command("say " + RANK_D->query_respect(ob) +
                        "�㻹�����ĺ��������һ��������㡣");
                return;
        }
        command("say ������ ���Ҿ�������ɡ�");
        command("recruit " + ob->query("id"));
}
