// renwoxing.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_bijian();

void create()
{
	set_name("������", ({ "ren woxing", "ren","woxing" }));
	set("title", BLU "������̽���"NOR );
	set("long", "ֻ����һ�ų��������ף���ɫѩ�ף����ް��Ѫɫ��üĿ���㣬
������ߣ�һͷ�ڷ���������һϮ������\n");
	set("gender", "����");
	set("class", "scholar");
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 70);
	set("per", 27);
	set("int", 70);
	set("con", 70);
	set("dex", 70);
       create_family("�������",1,"����");	
	set("max_qi", 26000);
	set("max_jing", 26000);
	set("neili", 54000);
	set("max_neili", 54000);
	set("jiali", 400);
	set("combat_exp", 9000000);
	set("score", 500000);

	set_skill("literate", 180);
	set_skill("force", 260);
	set_skill("dodge", 260);
	set_skill("unarmed", 260);
	set_skill("parry", 260);
	set_skill("sword", 260);
	set_skill("changquan", 360);
	set_skill("kuihua-xinfa", 360);
	set_skill("lingxu-bu", 360);
	set_skill("damo-jian", 360);
	set_skill("taiji-jian", 360);
	set_skill("huifeng-jian", 360);
	set_skill("taishan-sword", 360);
	set_skill("hengshan-jian", 360);
	set_skill("hengshan-sword", 300);
	set_skill("huashan-sword", 360);


	set_skill("songshan-jian", 380);
  set_skill("luoyan-jian",380);
  set_skill("shiba-pan",380);
  set_skill("liuhe-dao",380);
  set_skill("hengshan-jian",380);
  
  
  
	map_skill("dodge", "lingxu-bu");
	map_skill("force", "kuihua-xinfa");
	map_skill("unarmed", "changquan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");
          set_skill("sword", 380);
          set_skill("parry", 300);
        set_skill("literate",200);
          set_skill("dodge", 300);
          set_skill("unarmed", 300);
          set_skill("whip", 250);
          set_skill("force", 300);
         set_skill("tmzhang", 380);
        set_skill("staff", 160);
         set_skill("tmjian", 380);
         set_skill("tmdao", 380);
         set_skill("pmshenfa", 380);
          set_skill("strike",300);
          set_skill("cuff",300);
         set_skill("blade", 300);
         set_skill("tmdafa", 320);
set_skill("tmquan", 380);
        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        map_skill("strike", "tmzhang");
        map_skill("cuff", "tmquan");
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

prepare_skill("cuff","tmquan");

prepare_skill("strike","tmzhang");

        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        set("inquiry", ([
                "�Ƚ�" :  (: ask_bijian :),
                "����" :  (: ask_bijian :),
                "��ľ��" : "Ҫ�ú�ľ��Ϸ����ȿ�����Ľ�����\n",
                "��ӯӯ" : "���ѵ�֪����������\n",
                "������" : "�Ҿ������𽭺���������̽�������Ͱ���Ϊʦ�ɡ�\n",
                "�������" : "�ǵģ������������̰ɣ���������书��û���ܵС�\n",
	]) );
 	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
if (random(2)==0) 
{
	carry_object("/clone/weapon/changjian")->wield();
}
else
{
carry_object("/clone/weapon/gangdao")->wield();
}
}

void attempt_apprentice(object ob)
{
         if (ob->query_int() < 30) {
              command("say " + RANK_D->query_respect(ob) +
                        "�߿��߿����Ҳ����ɵ��˵����");
                return;
        }
         if (ob->query_dex() < 25) {
                command("say " + RANK_D->query_respect(ob) +
                        "���ֲ��ݣ����������ʦ�ɡ�");
                return;
        }
    if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000 ) {
        command("say �Һ�ľ�������������������������ֳ�������򽻵�������ذɣ�;\n");
                return;
        }
        command("say ������ ���Ҿ�������ɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title","��������ν����״�����");
}

int ask_bijian()
{
	object obj, me = this_player(), ob = this_object();
	message_vision("$N����˵���������������Ұݼ�����ǰ�����������ָ�̡���\n
$nЦ���������ÿ������������Ҽ�į���ɶ�л��������\n", me, ob );
	message_vision("$N���������ҡ���\n
$n���˵�ͷ��˵��������ֻ��������Ľ�����������Ĺ�
�У���˵����Ҳδ����ʤ�����㡣��\n\n", me, ob);
	say(HIR"�����д��һ���������ֽ�������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵��������һ�С���\n");
		return 1;
	}
	command("enable sword taiji-jian");
	say(HIR"�����д��һ�������䵱��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword huifeng-jian");
	say(HIR"�����д��һ���������ҽ�������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword songshan-jian");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword taishan-sword");
	say(HIR"�����д��һ������̩ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword huashan-sword");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword hengshan-sword");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword hengshan-jian");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵����������û�����С���\n");
		return 1;
	}

	obj = new("/d/heimuya/obj/heimu-ling");
	obj -> move(me);
	say("������˵��������λ" + RANK_D->query_respect(me)+"�����Ҿ�����һ���ľ��ɡ���\n");
	return 1;
}
