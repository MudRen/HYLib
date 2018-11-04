// tang wuhuo.c ���޻�

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_fail();
string  ask_job();

string ask_jianxi();
string ask_finish();
mixed names = ({
        ({
        "�����","����ĺ��¥","�����","ī��","����ͤ",
        "����","������","������","ź��С�","ź����Ʒ�",
        "����¥","������","ǧ���","÷԰","չ÷��",                
        "���䳡","��ľͤ","�ҽ���","���߸�","�ձ�", 
        "������","��䳤��","���Ͻ�¥","������¥","����¥",
        "����¥","���Ͻ�¥","�Ͻ�¥","������¥","ǧ���",
        }),
        ({
        "���Ͻ�¥","������¥","����¥",
        "����¥","���Ͻ�¥","�Ͻ�¥","������¥",
        }),
        });

void create()
{
	set_name("���޻�", ({ "tang wuhuo", "tang" }));
	set("nickname", HIW "���²���" NOR);
	set("long", 
		"�������ŵ��ߴ������еĽܳ��������Ϊ�˰������磬����\n"
		"���ȵ�����Ƣ��������������˳ơ����²����ƴ�����\n"
		"����Լ��ʮ���࣬Ц�ݿ��䣬˫Ŀ���о�â��˸��\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 98);
	set("int", 90);
	set("con", 90);
	set("dex", 92);
	
	set("qi", 30000);
	set("eff_qi", 30000);
	set("max_qi", 30000);
        set("jing", 30000);
	set("eff_jing", 30000);
	set("max_jing", 30000);
	set("neili", 80000);
	set("max_neili", 80000);
	set("jiali", 60);
	set("combat_exp", 6800000);
	set("score", 60000);

	set_skill("force", 200);
	set_skill("biyun-xinfa",320);
	set_skill("dodge", 200);
	set_skill("qiulinshiye", 280);
	set_skill("strike", 200);
	set_skill("unarmed",200);
	set_skill("biye-wu", 300);
	set_skill("parry", 200);
	set_skill("throwing", 280);
	set_skill("zhuihun-biao", 300);
	set_skill("literate", 100);

	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "biye-wu");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "zhuihun-biao");
	map_skill("throwing", "zhuihun-biao");
	
	create_family("����", 7, "����");
	set("class", "tangmen");

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "throwing.lianhuan" :),
		(: perform_action, "strike.meng" :),
		(: perform_action, "strike.wandu" :),
		(: perform_action, "dodge.rain" :),
                (: perform_action, "dodge.wu" :),
	}) );
        set("inquiry", ([
   	    "������"  : (: ask_jianxi :),
	    "job"  : (: ask_jianxi :),
   	    "����"  : (: ask_job :),
	    "huchenjob"  : (: ask_job :),
            "huchenfail" : (: ask_fail() :),
            "����ʧ��" : (: ask_fail() :),
   	    "���"  : (: ask_finish :),
	    "finish"  : (: ask_finish :),

        ]));
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
	setup();
	carry_object("/d/tangmen/obj/gangbiao1")->wield();
	carry_object("/d/tangmen/obj/qingduan")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("biyun-xinfa", 1) < 70) {
		command("say ������Ȼ�԰���Ϊ����������Ҫ����������"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ���ڱ����ķ��϶��µ㹦��");
		return;
	}
	if (ob->query_int() < 24) {
		command("say ��������ע�ص��ӵ���ѧ��Ϊ��");
		command("say ���ɹ���Ҫ���������ã��������������������Զ�⾳�����Բ����ǲ��еġ�");
		command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
		return;
	}
	command("say ������ѧ�������ú���ϰ�������ŷ�����");
	command("recruit " + ob->query("id"));
}

string ask_jianxi()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
        if( ob->query("family/family_name") != "����")
           {
                      message_vision("$N����$n���һ�������ɵ��Ӳ������������������ģ�\n", this_object(), ob);
                      return  "���ߡ�";
            }
    if ((int)ob->query_skill("biyun-xinfa",1) < 30 ) {
                      message_vision("$N����$n���һ������ı����ڹ�̫���ˣ�\n", this_object(), ob);
                      return  "���ߡ�";
    } 
     if ((int)ob->query_condition("guojob2_busy"))
        return  "��սӹ����񣬵Ȼ�������";

     if(ob->query_condition("tangmen_busy"))
        return  "��սӹ����񣬵Ȼ�������";

//     if(ob->query_condition("tangmen2_busy"))
//        return  "��սӹ����񣬵Ȼ�������";

	  if(ob->query("combat_exp")<10000)
      return  "��Ĺ���̫���ˡ�";
            if(ob->query_temp("tangmen"))
      return  "�㲻�����ڸɻ!";

	  where=names[0][random(30)];
	  ob->set_temp("tangmen",1);
	  ob->set_temp("tangmenjob",where);
          ob->apply_condition("tangmen_busy",9);
if (!ob->query_skill("biyun-xinfa",1))
{
ob->apply_condition("tangmen_busy",9);
}
          obn=new(__DIR__"saozhou");
          obn->move(ob);
	  return    HIY"�Ҹյõ���Ϣ�����ǵĵ�����������Ҫ������\n"+
           "          ��Ͽ�ȥ"+where+"��Щ������(zuogong)��\n"+
           "          �����б�����ɵ��������£����С�ġ�"NOR; 
}

string ask_finish()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
      if(!ob->query_temp("tangmen"))
      return  "��û����ɹ��!";

	  if(!ob->query_temp("tangmenok"))
      return  "��Ļ�û���갡!";
        ob->delete_temp("tangmen");
        ob->delete_temp("tangmenjob");
        ob->delete_temp("tangmenok");
        ob->add("combat_exp",50+random(150));
        ob->add("potential",25+random(100));
	  return    HIY"���úã���\n"+
           "          ��ָ������ֹ���ɡ�\n"+
           "          ��ľ����Ǳ��������!"NOR; 
}


string ask_job()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
        if( ob->query("family/family_name") != "����")
           {
                      message_vision("$N����$n���һ�������ɵ��Ӳ������������������ģ�\n", this_object(), ob);
                      return  "���ߡ�";
            }
    if ((int)ob->query_skill("biyun-xinfa",1) < 30 ) {
                      message_vision("$N����$n���һ������ı����ڹ�̫���ˣ�\n", this_object(), ob);
                      return  "���ߡ�";
    } 
if ((int)ob->query_condition("guojob2_busy"))
        return  "��սӹ����񣬵Ȼ�������";

     if(ob->query_condition("tangmen2_busy"))
        return  "��սӹ����񣬵Ȼ�������";

//     if(ob->query_condition("tangmen_busy"))
//        return  "��սӹ����񣬵Ȼ�������";

     if(ob->query("combat_exp")<100000)
      return  "��Ĺ���̫���ˡ�";
        if (ob->query_temp("tmhw")) {
                command("kick " + ob->query("id"));
      return  "�Ҳ��Ǹ�������������";
                }
        if (ob->query_temp("tmhwjob")) {
                command("kick " + ob->query("id"));
      return  "�Ҳ��Ǹ�������������";
                }
      
	  where=names[1][random(7)];
	  ob->set_temp("tmhw",1);
	  ob->set_temp("tmhwjob",where);
          ob->apply_condition("tangmen2_busy",22);
if (!ob->query_skill("biyun-xinfa",1))
{
ob->apply_condition("tangmen2_busy",25);
}
          obn=new(__DIR__"ling");
          obn->set("usename",ob->query("name"));
          obn->move(ob);
	  return    RED"�ղ����������棬��ν���������ɣ���Ȼ��͵Ϯ���š�\n"+
           "          ��Ͽ�ȥ"+where+"�ͻ�����һ�𻤳�(huchen)��\n"+
           "          ������������͵Ϯ���������ǡ�"NOR; 
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query_temp("tmhwjob")) {
                command("sigh");
                command("say ��ô���£��㶼�����ã�Ҳ�գ���ȥ��.");
          destruct(present("tm lingpai",me));
          me->apply_condition("tangmen2_busy",33);
       me->delete_temp("tmjob");
        me->delete_temp("tmhw");
        me->delete_temp("tmhwjob");
        return 1;
                }
}

