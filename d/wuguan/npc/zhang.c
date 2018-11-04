//zongguan.c����ܹ�
//by cool 98.3.25
#include <ansi.h>

inherit NPC;
string *names = ({"��ɨ��","��ľͷ","����","���˵�","����",});


string ask_job();

void create()
{
	set_name("�ŷ�", ({ "zhang feng","zhang","zong guan", "zongguan" }));
	set("title", "��������ܹ�");
	set("gender", "����");
	set("age", 45);
	set("str", 27);
	set("dex", 26);
	set("long", "������ò�Ͱ���Ц�Ǻǵģ�һ���ø����̴���\n");
	set("combat_exp", 700000);
	set("shen_type", 1);
	set("attitude", "friendly");
       set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),(: perform_action, "strike.diezhang" :),
        }) );

	set_skill("unarmed", 120);
	set_skill("force", 130);
       set_skill("strike", 160);
	set_skill("hammer", 100);
       set_skill("kunlun-zhang", 160);
       set_skill("xuantian-wuji", 160);
       set_skill("kunlun-shenfa", 160);
       set_skill("dodge", 160);
	set_skill("parry", 160);
      map_skill("dodge", "kunlun-shenfa");
      map_skill("parry", "kunlun-zhang");
      map_skill("force", "xuantian-wuji");
      map_skill("strike", "kunlun-zhang");
      prepare_skill("strike","kunlun-zhang");


	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);


       set("qi", 2000);
	set("max_qi", 2000);
	set("neili", 2500); 
	set("max_neili", 2500);
	set("jiali", 150);
 set("inquiry", 
                ([
                     	"����" : (: ask_job :),
                            "job" : (: ask_job :),
                         	"����" : "��ȥ��Ʒ��������Ҫ�ɣ�",
  
                ]));


	setup();
}
void init()
{
        object ob;

        ::init();
if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer"))
       {      command("say �㾹�������ɱ��! \n");

		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	} else
       { 
       if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
       }
		add_action("do_task","task");
}
string ask_job()
{
        object me;
        object ob;
        string target;
        ob=this_player();
        me=this_object();
       target = names[random(sizeof(names))];
        if (ob->query_temp("job_name"))
                return ("�㲻���Ѿ����˹����𣿻�����ȥ����\n");
            if (ob->query("combat_exp")>=30000)
                     return ("�㹦����ô�ߣ�����û��ʲô�ʺ���Ĺ����ˡ�\n");
	ob->set_temp("job_name",target);
       ob->apply_condition("wuguan_job",random(3)+4);
	return "���������кö���Ҫ��������ȥ����Ʒ���칤�ߣ�Ȼ��ȥ��Ժ"+ target+ "�ɡ�";
}
int do_task(string arg)
{
	object ob,me;
	ob=this_player();
	me=this_object();
	if(!(arg||arg=="ok")) return 0;
       if(!ob->query_temp("job_name")) 
            return notify_fail("û���㹤��������ô���������ˣ�\n");
              if (interactive(ob)&&(int)ob->query_condition("wuguan_job")) {
                 command("slap "+ob->query("id"));
                 return notify_fail(RED "����ô������ˣ��ǲ��ǻ�û���갡���Ը����������"NOR);
                 }    
       if(!ob->query_temp("mark/����")) 
            return notify_fail("���Ȱѹ��߻������������������ɡ�\n");
      	if(!(ob->query_temp("mark/������")||ob->query_temp("mark/������")||ob->query_temp("mark/������")||ob->query_temp("mark/������")||ob->query_temp("mark/ɨ����")||ob->query_temp("mark/������")))
            return notify_fail("��͵����������ɻ��㲻ȥ�ɣ������칦! \n");
	if(arg=="ok"&&(ob->query_temp("mark/������")||ob->query_temp("mark/������")||ob->query_temp("mark/ɨ����")||ob->query_temp("mark/������")||ob->query_temp("mark/������")||ob->query_temp("mark/������")))
	{
		command("smile "+ob->query("id"));
		command("say �ã�"+RANK_D->query_respect(ob)+"�����úã����Ǹ���Ľ��ͣ�");
             if (random(10)<7)
            {
              me->add_money("coin",(int)(ob->query_skill("force",1)/2)+65);
              command("give "+ob->query("id")+" "+((int)(ob->query_skill("force",1)/2)+50)+" coin");
             }else{
              me->add_money("silver",(int)(ob->query_skill("force",1)/5)+1);
              command("give "+ob->query("id")+" "+((int)(ob->query_skill("force",1)/5)+1)+" silver");
              }
             	ob->add("potential",(int)(ob->query_skill("force",1)/5)+30);
             if(ob->query("potential") > ob->query("max_pot")) ob->set("potential", ob->query("max_pot"));
              ob->add("combat_exp",(int)(ob->query_skill("force",1)/5)+60);
		ob->delete_temp("job_name");
	       ob->delete_temp("mark");
		return 1;
	}
	return 1;
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
         
 //     if (interactive(ob)&&(int)ob->query_condition("wuguan_job")) {
 //                ob->apply_condition("wuguan_job",random(3)+7);
 //               command("slap"+ob->query("id"));
 //               return notify_fail(RED "������ͻ����ˣ����һ�ȥ������! "NOR);
 //               }   
      if(ob->query_temp("job_name")) return; 
//      if(ob->query_temp("mark/����")&&(ob->query_temp("mark/������")||ob->query_temp("mark/������")||ob->query_temp("mark/������")||ob->query_temp("mark/������")||ob->query_temp("mark/ɨ����")||ob->query_temp("mark/������")))
//	{ command("nod" +ob->query("id"));
//         command("say �㹤�����Ĳ������Ը��Ҹ�����(task ok)! \n");
//         return; 
//        }
       if ( ob->query("combat_exp") < 30000 ) {
       command("bow "+ob->query("id"));
       command("say ��λ" + RANK_D->query_respect(ob)
				+ "��������ȱ���֣�����������칤��"HIR"(ask zhang about job)"NOR"������\n");
       }
}				
