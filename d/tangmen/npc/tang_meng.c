// tang meng.c ����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "tang meng", "tang" }));
	set("nickname", HIW "������" NOR);
	set("long", 
		"�������ŵ��ߴ������еĽܳ������ΪƢ���𱬣��������\n"
		"�ڽ�����ɱ�����ٴ����֮ͽ��������� ������\n"
		"����Լ��ʮ���࣬��Ĵ�׳��������Բ,�����ֵĹ����������ڡ�\n");
	set("gender", "����");
	set("age", 30);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 32);
	set("int", 30);
	set("con", 30);
	set("dex", 32);
	
	set("max_qi", 11000);
	set("max_jing", 13000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 200000);

	set_skill("force", 120);
	set_skill("biyun-xinfa",120);
	set_skill("dodge", 120);
	set_skill("qiulinshiye", 220);
	set_skill("strike", 120);
	set_skill("unarmed",120);
	set_skill("biye-wu", 120);
	set_skill("parry", 120);
	set_skill("throwing", 180);
	set_skill("pili-biao",380);
	set_skill("literate", 80);
	set_skill("dusha-zhang", 180);
	set_skill("lansha-shou", 180);
	set_skill("hand", 180);
	set_skill("strike", 180);
	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "biye-wu");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "pili-biao");
	map_skill("throwing", "pili-biao");
		map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
	create_family("����", 7, "����");
	set("class", "tangmen");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "strike.meng" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/d/tangmen/obj/gangbiao1")->wield();
	carry_object("/d/tangmen/obj/qingduan")->wear();
}

void init()
	{
		::init();
	remove_call_out("greeting");
	call_out("greeting", 1, this_player());
}


void greeting(object ob)
{
	mapping fam;
        int i ;
	object me;
	object* obj;
	me = this_object();
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight"))
	{
 	     if (!(fam = ob->query("family")) || fam["family_name"] != "����")
		{
                   if (ob->query("shen")>-1000)      
			{
			command("say �������������ã���Ҫ����������߶�");
			obj = all_inventory(environment(me));
			for(i=0; i<sizeof(obj); i++) 
			{
			if(obj[i]==this_player()) continue;
			if(obj[i]==me) continue;
			if((obj[i]->query("shen")<-1000)) 
			{
				command("say ����޺�����Ϊ���󱲣����ҽ�����������!!");
				me->kill_ob(obj[i]);
				obj[i]->kill_ob(me);
			}
			}
			}	

	   else{
			command("say һ��Ҫɱ�����⽭�����࣡");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		
			}

		}    
	}       

}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 10000 )
	 {
		command("say ����ͽ��ע�ص��У�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	if (ob->query_str() < 25) {
		command("say ����Ȼ�õ��ǰ�����");
		command("say �����ҵ�������Ҫ���к�ǿ�ı�����");
		command("say " + RANK_D->query_respect(ob) + "�������ϻ���Ҫ���¹���");
		return;
	}
	if ((int)ob->query_skill("biyun-xinfa", 1) < 80) {
		command("say ������Ȼ�԰���Ϊ����������Ҫ����������"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ���ڱ����ķ��϶��µ㹦��");
		return;
	}
	if (ob->query_int() < 25) {
		command("say ��������ע�ص��ӵ���ѧ��Ϊ��");
		command("say ���ɹ���Ҫ���������ã��������������������Զ�⾳�����Բ����ǲ��еġ�");
		command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
		return;
	}
	command("say ���������Ҿ������㣬��ס�Ժ�Ҫ�ڽ�����������ร�");
	command("recruit " + ob->query("id"));
}
