// jianxin.c
// ����(diabio)��Ȩ����
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_fail();
string  ask_job();
string ask_me();
string ask_dao();
string ask_give();
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
        "��Ż�����","��Ż���������","ţ���",
        "�ٲ�","���˴�","������","������",
        }),
        });

void create()
{
        set_name( "糴彣��" ,({ "jian xin", "xin" }));
        set("nickname", HIW"�ε��R"NOR);
              set("title", HIR"ǰά��־ʿ"NOR);
        set("gender", "����");
        set("age", 26);
        set("long",
            "�����Ƿ�����������ʮ�������š�ɱ���߰ε��롣����ɫ\n"
            "���㣬һ�������Ե�ģ����������һ�쳤����ʮ�ֵ��̡�һ\n"
            "��Ҳ����벻����������ά��ʱ�������ŷ�ɥ����ɱ����\n"
            "�ε��룬һ�ַ���������ʹ�ĳ����뻯��\n");
        set("attitude", "peaceful");
        set("str", 47);
        set("int", 42);
        set("con", 45);
        set("per", 45);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
        }));
        set("qi",16000);
        set("eff_jing",15000);
        set("jing",15000);
        set("eff_qi",16000);
        set("max_qi",16000);
        set("max_jing",15000);
        set("neili", 20000);
        set("max_neili", 25000);
        set("jiali", 50);
        set("shen",5000000);

        set("combat_exp", 6000000);

        set_skill("unarmed", 250);
        set_skill("force", 260);
        set_skill("parry", 280);
        set_skill("dodge", 250);
                set_skill("cuff",280);
        set_skill("blade", 320);
        set_skill("literate", 250);
        set_skill("xuanhualiu-quanfa", 250);
        set_skill("feitian-yujianliu",320);
        set_skill("wuxing-dun", 320);
        set_skill("shayi-xinfa", 320);
        set_skill("shayi", 320);
//        set_skill("bearart", 1100);
       

        map_skill("force", "shayi-xinfa");
        map_skill("parry", "feitian-yujianliu");
        map_skill("blade", "feitian-yujianliu");
        map_skill("dodge", "wuxing-dun");
        map_skill("unarmed", "xuanhualiu-quanfa");
       set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("����������", 6, "����");
        set("book_count",1);
        set("inquiry", ([
           "���е�": (: ask_me :),
           "����": (: ask_dao :),
           "���е����": (: ask_give :),
           "ʮ��":     "����־־���ټ���ʮ����֡�",
           "��ͷ����": "���Ǳ��ų����������������߽���,��û����ʵ�ĸ��ױ����׳��ԡ���������(accept test)��\n",
           "���е�": (: ask_me :),
   	    "ά��"  : (: ask_job :),
	    "shirenjob"  : (: ask_job :),
            "jobfail" : (: ask_fail() :),
            "����ʧ��" : (: ask_fail() :),
            ]));
        setup();
      carry_object("/clone/cloth/cloth")->wear();
      carry_object(__DIR__"obj/shoes")->wear();
          carry_object(__DIR__"obj/nirendao")->wield();
}

void attempt_apprentice(object ob)
{
        	if ((int)ob->query_skill("huoxinliu-jianfa", 1) < 180) {
		command("say ��Ļ���������̫���ˣ���δ��������Ķ������ѧϰ�ҵ��书�ء�"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�㻹�ǰѻ���������������������ɣ�");
		return;
        }
	if ((int)ob->query_skill("shayi-xinfa", 1) < 120) {
		command("say ���ɱ���ķ�̫��,���¿��Ʋ���ɱ�⡣"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�㻹�ǰ�ɱ���ķ�������������ɣ�");
		return;
	}
	if ((int)ob->query_skill("aikido", 1) < 120) {
		command("say ��Ŀ��ֵ�̫�͡�"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�㻹�ǰѿ��ֵ�������������ɣ�");
		return;
	}
	if ((int)ob->query_skill("wuxing-dun", 1) < 120) {
		command("say ������ж�̫�͡�"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�㻹�ǰ����ж�������������ɣ�");
		return;
	}
    if ((int)ob->query_skill("shayi", 1) < 120)
    {
        command("say ����֮������ɱ�⡣");
        command("say " + RANK_D->query_respect(ob) +
            "���ɱ��̫���ˣ�");
        return;
    }
	if ((int)ob->query("shen") < 200000) {
		command("say �����������Ǿ���֮���������аħ���ѧ������Σ�����֡�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	if (ob->query_int() < 30) {
		command("say ����������֮��ȫ��һ�����֡�");
		command("say ���������ô�������������������ء�");
		command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
		return;
	}
	command("chat �������������������������Ľ�����");
       command("chat " + RANK_D->query_respect(ob) + "ϣ�����ܽ�����������������");
	command("recruit " + ob->query("id"));
	ob->set("title",HIR"��������������"HIW"ά��־ʿ"NOR);
       ob->set("class", "yujianliu");
}

string ask_me()
{
        object me=this_player();
        me->set_temp("tmark/��",1);
        return("����С����������ɱ�˺�����ʦ����һ�����е���ϣ���Ժ�ֻ�������˶�����ɱ��\n");
}

string ask_dao()
{
        object me=this_player();
        if(me->query_temp("tmark/��")==1) {
                me->add_temp("tmark/��",1);
                return("�����ҵ����е�����,����ɱ���潣֮�Ƶ���ƽ�������ġ�\n");
        }
        else {
                me->set_temp("tmark/��",0);
                return("�ձ��������������ĵط�����\n");
        }
}

string ask_give()
{
        object ob,me=this_player();
        if(me->query_temp("tmark/��")==2) {
                me->set_temp("tmark/��",1);
                if(query("book_count")>0) {
                        ob=new(__DIR__"obj/nirendao");
                        ob->move(me);
                        add("book_count",-1);
                        return "�ðɣ���ʹ�����ȥ����ƽ��ȥ�ɡ�\n"
                                                        +"糴彣�ĸ����һ�����е���\n";
                }
                else
                        return("�������ˣ����е��Ѿ����Ҹ��ˡ�\n");
        }
        else {
                me->set_temp("tmark/��",0);
                return  RANK_D->query_respect(me) +
                        "��������ҽ��������ɣ�\n";
        }
}
void init()
{
        ::init();
        add_action("do_accept", "accept");
}
int do_accept(string arg)
{
        mapping guild;

        if( arg== "test" ) {
	if((string)this_player()->query("family/family_name") != "����������") 
		{
			command("say �㲻�Ǳ����������ѧϰ������������\n");
			return 1;
		}

	else if(this_player()->query("feitian-yujianliu")>150)
		{
			command("say ���Ȱѽ����������������Ұɡ�\n");		return 1;}
	else if(this_player()->query("shen")<-50000)
		{
			command("say ��˾�ѧ�̸�����Ҳ��Σ���˼䣡\n");		return 1;}
	else if(this_player()->query("dex")<30)
		{
			command("say ����̫���᲻����ͷ������\n");
		return 1;}
	else if(this_player()->query("combat_exp")<1000000)
		{
			command("say ��ʵս����̫��Ҳ��ܽ��㣿��\n");
		return 1;}


	
                say("\n糴彣�ĵ��˵�ͷ��˵�����ܺã����������У����ǵ�һ��....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("qi") < 1 ) {
                        
say("糴彣��̾�˿�����˵������С����һ�ж��Ų���������̫�Բ�����....\n");
                 this_player()->die();
	       return 1;
		}
                say("\n糴彣��˵������������С���ĵڶ���....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("qi") < 1 ) {
                        
say("糴彣��̾�˿�����˵�����������̫Զ��....\n");
                this_player()->die();     
	   return 1;
                }
                say("\n糴彣��˵����С������������....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("qi") < 1 ) {
                        
say("糴彣��̾������ϧ��������������Ƿȱ....\n");
                       this_player()->die();
 return 1;
                }
                
say("\n糴彣��Ц����С���Ͱѷ������������߽������ڸ����ˣ�ϣ���㲻Ҫ����������Ϊ��\n\n");
                this_player()->set("feitian/jiu",1);
	return 1;
        }
        return 0;
}
void kill_ob(object me)
{
	command("say С��������ɱ�ˣ���αؿ������أ�����\n");
	::kill_ob(me);
}


string ask_job()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
        if( ob->query("family/family_name") != "����������")
           {
                      message_vision("$N����$n���һ�������ɵ��Ӳ������������������ļ�ϸ��\n", this_object(), ob);
                      return  "���ߡ�";
            }

     if(ob->query_condition("feitian2_busy"))
        return  "��սӹ����񣬵Ȼ�������";

     if(ob->query("combat_exp")<500000)
      return  "��Ĺ���̫���ˡ�";

        if (ob->query_temp("fthw")) {
                command("kick " + ob->query("id"));
      return  "С�����Ǹ�������������";
                }
        if (ob->query_temp("fthwjob")) {
                command("kick " + ob->query("id"));
      return  "С�����Ǹ�������������";
                }
      
	  where=names[1][random(7)];
	  ob->set_temp("fthw",1);
	  ob->set_temp("fthwjob",where);
          ob->apply_condition("feitian2_busy",8);
if (!ob->query_skill("shayi-xinfa",1))
{
ob->apply_condition("feitian2_busy",16);
}
          obn=new(__DIR__"ling");
          obn->set("usename",ob->query("name"));
          obn->move(ob);
	  return    HIM"־־�۵�����Ҫ��ά�µ������ԣ�Ҫ�ɱά�µ���\n"+
           "          ��Ͽ�ȥ"+where+"������һ��ʱ��(shouwei)��\n"+
           "          �������������Ļ�����С���������ǡ�"NOR; 
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query_temp("fthwjob")) {
                command("sigh");
                command("say ��ô���£��㶼�����ã�Ҳ�գ���ȥ��.");
          destruct(present("ft lingpai",me));
          me->apply_condition("feitian2_busy",6);
       me->delete_temp("ftjob");
        me->delete_temp("fthw");
        me->delete_temp("fthwjob");
        return 1;
                }
}
