#include <ansi.h>
inherit NPC;

void create()
{
	set_name("���ͷ", ({ "li jiaotou", "li","jiaotou"}));
	set("long", "һ������ڵĽ�ͷ��ר�Ÿ���������书��\n");
	set("gender", "����");
	set("age", 30);
	set("attitude", "heroism");
	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	set("qi", 300);
	set("max_qi", 300);
	set("max_jing", 200);
	set("neili", 300);
	set("max_neili", 300);
	set("combat_exp", 6000);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("leg", 60);
        set_skill("finger", 60);
	set_skill("parry", 60);
	set_skill("blade", 60);
	set_skill("hand", 60);
	setup();
        carry_object("clone/cloth/cloth")->wear();
	carry_object("clone/weapon/changjian")->wield();
}
void init()
{
	object ob;
	::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int recognize_apprentice(object ob)
{
		
    if (ob->query("combat_exp",1)>25000){
      command("shake");
      command("say ���Ѿ���һ�������ˣ������Լ����������ˡ� \n"); 
      return 0;
      }
    return 1;	
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
         
            if(ob->query("combat_exp",1)>=10000) return
;

       command("bow "+ob->query("id"));
       command("say " + RANK_D->query_respect(ob)
				+ "������Կ��һ�Ĺ���"HIR"(cha li)"NOR",���Ը���ѧ����"HIR"��xue li xxx)"NOR"��\n");
           
}

int is_apprentice_of() {return 1;}
