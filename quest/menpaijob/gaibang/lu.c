// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;
#include "huajob.h"
void consider();

string ask_me();
void create()
{
	set_name("³�н�", ({"lu youjiao", "lu", "youjiao"}));
	set("title", "ؤ��Ŵ�����");
	set("nickname", "�ư���ͷ");
	set("gender", "����");
        set("beggarlvl",9);
	set("age", 45);
	set("long", 
		"³�н���Ȼ�书�㲻�ö�����֣������ڽ�����ȴ����������\n"
		"��Ϊ����ؤ�����������壬���¹������䣬��ú��߹������ء�\n");
	set("attitude", "peaceful");
        set("class", "beggar");
	set("str", 235);
	set("int", 232);
	set("con", 235);
	set("dex", 230);

	set("qi", 56900);
	set("max_qi", 56900);
	set("jing", 10000);
	set("max_jing", 10000);
	set("neili", 242000);
	set("max_neili", 242000);
	set("jiali", 100);
	
	set("combat_exp", 3500000);
	set("score", 20000);
	set("book_count", 1);
			set_skill("fengmo-zhang",250);
	set_skill("liuhe-zhang",250);
	set_skill("strike",290);
	set_skill("force", 190); // �����ڹ�
	set_skill("huntian-qigong", 290); // ��������
	set_skill("unarmed", 195); // ����ȭ��
	set_skill("xianglong-zhang", 280); // ����ʮ����
	set_skill("dodge", 250); // ��������
	set_skill("xiaoyaoyou", 250); // ��ң��
	set_skill("parry", 250); // �����м�
	set_skill("staff", 255); // ��������
	set_skill("begging", 250);
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
       set("inquiry",([
                 "job" : (: ask_job :),
		 "�л���" : (: ask_me :),
       ]));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
        }) );

	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        
	create_family("ؤ��", 18, "�Ŵ�����");
	setup();
	carry_object("kungfu/class/gaibang/obj/jiaohuaji")->wield();
}

void attempt_apprentice(object ob)
{
	if ( (int)ob->query("int") >= 25 ) {
		command("say ����ؤ�������һ���Ը���Ϊ����" + 
		RANK_D->query_respect(ob) + "�ϻ۹��ˣ��ƺ�����ѧؤ��Ĺ���");
		return;
	}
	command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
	"�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "ؤ��")
		return this_player()->query("name") + "�뱾��������������֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ��л����Ѿ������˳���!!";
	add("book_count", -1);
	ob = new("kungfu/class/gaibang/obj/jiaohuaji");
	ob->move(this_player());
	return "�������������ϲ��������ġ�����ȥ�������˼ң�����ܸ��˵�!!";
}

int hit_ob(object me, object ob, int damage)
{
if (ob!=me)
{
ob->start_busy(12);
	ob->apply_condition("qx_snake_poison", 220);
	ob->apply_condition("wugong_poison", 140);
        ob->apply_condition("chanchu_poison", 140);
        ob->apply_condition("xiezi_poison", 140);
        ob->apply_condition("snake_poison", 140);
        ob->apply_condition("zhizhu_poison", 140);
        tell_object(ob, HIG "����ñ����еĵط�һ��������\n" NOR );
}
}