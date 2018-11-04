// zhang.c ����
// zly 99.6.12

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({"zhang ma", "zhang", "ma"}));
	set("gender", "Ů��");
	set("shen_type", 1);
	set("age", 48);
	set("long", 
"����������Ӷ�����裬������Ц�����ģ���֪����ʲôϲ�¡�\n"
	);
	
	set("str", 20);
	set("int", 10);
	set("con", 10);
	set("dex", 15);

	set("max_qi", 200);
	set("eff_qi", 200);
	set("qi", 200);
	set("jing", 100);
	set("eff_jing",100);
	set("max_jing", 100);
	set("neili", 250);
	set("max_neili", 250);
	set("jiali", 10);
	
	set("combat_exp", 5000);

	set_skill("force", 40);		
	set_skill("huntian-qigong", 40);	
	set_skill("dodge", 40);			
	set_skill("xiaoyaoyou", 40);		
	set_skill("parry", 40);			
		
	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");

	setup();
        carry_object("/clone/misc/cloth")->wear();        
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "�����ֺǺǵض���" + RANK_D->query_respect(ob) + "˵����������������ã�˫ϲ���ţ����� \n");
                        break;
                case 1:
                        say( "����Ц�ŵ�: ������������ү���ٵ�������С�㶩��Ĵ�ϲ���ӣ���λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
        }
}

int accept_object(object who, object ob)
{
        
          if((string)ob->query("id") == "jin chai")
        {
         command("ah"+ (string)who->query("id"));
         command("say �ⲻ��С��Ľ���������......��Ŷ����ӭ��ӭ���������\n");
         who->set_temp("yyd_jinchai", 1);
         remove_call_out("destroying");
         call_out("destroying", 1, ob);
         return 1;
}
        return 0;
}

void destroying(object obj)
{     
        destruct(obj);
        return;
}     
