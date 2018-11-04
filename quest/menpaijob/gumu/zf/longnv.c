// longnv.c С��Ů

// 1998.9 by Lgg

#include <ansi.h>

inherit NPC;
string ask_job();
string ask_yunv();
string ask_me();
string ask_shoutao();
string ask_suo();
string ask_zhen();
int ask_fail();
void create()
{
        set_name("С��Ů", ({"long nv", "long"}));
        set("gender", "Ů��");
        set("age", 18);
        set("long",
                "����һϮ��ɴ��İ��£��������������������һͷ�ڷ�֮�⣬ȫ��ѩ�ף���\n"+
                "�����������ף�ֻ�Ǽ���������һ��Ѫɫ.��һ���������£���������������\n"+
                "ѩ���������֮�������䣬ʵ��������������¡������ݡ�\n");
        set("attitude", "friendly");

        set("per", 30);
        set("str", 60);
        set("int", 67);
        set("con", 66);
        set("dex", 68);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
                (: perform_action, "sword.hebi yang" :),
            		(: command("perform sword.hebi yang") :),
                (: perform_action, "unarmed.youju" :),
                (: perform_action, "unarmed.wuqing" :),
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                "С��Ů���ĵص�������֪����������������п����Ҵ��������ϵ��֣���\n", 
                "С��Ů�૵�������Ů����ȫ�潣�ϱڣ��ǿ������޵С�����...����ȥ����һ�����أ���\n",
                "С��Ů�����̾�˿�����ת��ͷȥ��\n",
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
                (: perform_action, "unarmed.youju" :),
                (: perform_action, "unarmed.wuqing" :),
        }));

        set("qi", 16500);
        set("max_qi", 16500);
        set("jing", 16600);
        set("max_jing", 16600);
        set("neili", 34000);
        set("max_neili", 34000);
        set("jiali", 200);

        set("combat_exp", 6000000);
        set("score", 0);

        set_skill("force", 250);
        set_skill("throwing", 300);
        set_skill("whip", 260);
        set_skill("yinsuo-jinling", 320);
        set_skill("yangyanshu", 380);
        set_skill("yunv-xinfa", 310);    //��Ů�ķ�
        set_skill("sword", 150);
        set_skill("yunv-jian", 320);     //��Ů��
        set_skill("quanzhen-jian",130);  //ȫ�潣
        set_skill("dodge", 260);
        set_skill("yunv-shenfa", 320);   //��Ů��
        set_skill("parry", 150);
        set_skill("hubo", 120);          //˫�ֻ���
        set_skill("unarmed",150);
        set_skill("meinv-quan", 320);    //��Ůȭ��
        set_skill("literate",120);
        set_skill("qufeng",250);         //����֮��
        set_skill("wuzhan-mei",250);
        set_skill("strike",200);
        set_skill("tianluo-diwang",320);         //����֮��

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "meinv-quan");

        create_family("��Ĺ��", 3, "����");


        set("book_count", 1);
        set("count",3);
        set("yfzhen",3);
        set("inquiry", ([
                "����" : (: ask_me :),
                "���" :  "��֪���ҹ��������䣿\n",
                "��Ů����" : "��Ů������ȫ�潣���ϱڣ������޵У�\n",
                "��Ĺ��" : "�ҵ�����ʦүү������������ʦ��һ����ˣ�����...\n",
                "��Ů�ľ�" : (: ask_yunv :),
                        "job" : (: ask_job :),
                        "����" : (: ask_job :),
                        "ʧ��" : (: ask_fail :),
                        "fail" : (: ask_fail :),
	"������":(: ask_suo :),
	"��˿����":(: ask_shoutao :),
	"�����":(: ask_zhen :),
        ]) );

        set("env/wimpy", 40);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
        setup();

        carry_object(__DIR__"obj/shunvjian")->wield();
        carry_object(__DIR__"obj/baipao")->wear();
	carry_object("/d/gumu/obj/jinling-suo");
	carry_object("/d/gumu/obj/jinsi-shoutao");
	carry_object("/d/gumu/obj/si_cloth");

}

void attempt_apprentice(object ob)
{
	if(ob->query("per") < 20)
	{
        	command("say ����ʵ�ڲ��ҹ�ά������ѧ������Ů�ķ���\n");
	}
	else
	{
	        command("say �ðɣ��Ҿ����������ͽ���ˡ�\n");
        	command("recruit " + ob->query("id"));
	}
}

void init()
{
        ::init();
	add_action("do_killing", "kill");
	add_action("do_killing", "touxi");
	add_action("do_killing", "hit");
	add_action("do_killing", "ansuan");
	add_action("do_killing", "qiangjian");
}

int do_killing(string arg)
{
	
	object player, victim, weapon;
	string name;
	player = this_player();
	if( !arg) return 0;
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = (string)victim->name();
		if( (string)name == "���")
		{
		message_vision("$N΢΢һЦ������������������! \n", this_object());
		this_object()->kill_ob(player);
		player->kill_ob(this_object());
		victim->kill_ob(player);
		return 1;
		}
	}
	return 0;		
}

string ask_yunv()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "��Ĺ��")
                return RANK_D->query_respect(this_player()) +
                "�뱾�ɺ��޹ϸ𣬺��������ɵ��ľ���";
        if (query("book_count") < 1)
                return "�������ˣ����ɵ���Ů�ľ��Ѿ�����ȡ���ˡ�";
        add("book_count", -1);
        ob = new("/clone/book/yunvjing1");
        ob->move(this_player());
        return "�ðɣ��Ȿ����Ů�ľ������û�ȥ�ú��ж���";
}


string ask_me()
{
        object ob;

        if(query("count") < 1)
                return "��֪�����������䣿";

        add("count", -1);
        ob=new(__DIR__"obj/junzijian");
        ob->move(this_player());
        return "������ӽ��͸��������������������ʱ���뽻������";
}

int recognize_apprentice(object ob)
{
        mapping myfam;
        if (!ob->query("family"))
        return 0;
        myfam = (mapping)ob->query("family");
        if ( myfam["family_name"] == "��Ĺ��") return 1 ;
        if ((int)ob->query_temp("tmark/��") == 1 )
        message_vision("С��Ů̾�˿���������$N��˵�������ǵ�Ե���Ѿ�����,\n"
                          "��Ҳûʲô�����ɽ�����ˡ�\n", ob);
        if (!(int)ob->query_temp("tmark/��"))
                return 0;
        ob->add_temp("tmark/��", -1);
        return 1;
}

int accept_object(object who, object ob)
{

        if ( (string) ob->query("id") =="yufeng" ) {
                remove_call_out("destroying");
                call_out("destroying", 1, this_object(), ob);
                if (!(int)who->query_temp("tmark/��")) who->set_temp("tmark/��",0);
                message_vision("С��Ů������䣬���ĵ�̾�˿�����˵����\n"
                               "�ѵ��㻹�����ҵ����ҵ�����ͻ��������\n"
                               "�Դ�������ѧ�㹦��\n", who);
                who->add_temp("tmark/��", 80);
                //ob->die();
                return 1;
        }
        return 0;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}


string ask_suo()
{
	object me=this_player();
	object obn;
	mapping myfam;
if(!me->query("family"))
		return "����˭��?�Ҳ���ʶ�㰡��\n";

	if (query("count") < 1)
		return "�������ˣ��������Ѿ�����ȡ���ˡ�\n";

	if(me->query_temp("������",1))
		return "���Ǹ���������\n";
		
	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "��Ĺ��")
       	if(myfam["generation"] == 4)
            {
            	if(me->query("class")==!"taoist")
            	{
            		obn=new("/d/gumu/obj/jinling-suo");
            		obn->move(me);
            		add("count", -1);
            		me->set_temp("������",1);
            		return "�������������͸���ѡ�";
            	}
            	else
            	{
            		command("say ������ʦ��ĵ��ӣ��Ҹ���Ҫ���㣿.\n");
            		return 0;
            	}
        }
        else
        {
        	return 0;
        }
}	
string ask_shoutao()
{
	object me=this_player();
	object obn;
	mapping myfam;
	if (query("count") < 1)
		return "�������ˣ���˿�����Ѿ�����ȡ���ˡ�\n";

	if(me->query_temp("��˿����",1))
		return "���Ǹ���������\n";

if(!me->query("family"))
		return "����˭��?�Ҳ���ʶ�㰡��\n";
		
	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "��Ĺ��")
       	if(myfam["generation"] == 4)
            {
            	if(me->query("class")==!"taoist")
            	{
            		obn=new("/d/gumu/obj/jinsi-shoutao");
            		obn->move(me);
            		add("count", -1);
            		me->set_temp("��˿����",1);
            		return "��˫��˿���׾��͸���ɡ�\n";
            	}
            	else
            	{
            		command("say ������ʦ��ĵ��ӣ��Ҹ���Ҫ���㣿.\n");
            		return 0;
            	}
        }
        else
        {
        	return 0;
        }
}	
string ask_zhen()
{
	object me=this_player();
	object obn;
	mapping myfam;
	if (query("yfzhen") < 1)
		return "�������Ѿ�û��������ˡ�\n";
if(!me->query("family"))
		return "����˭��?�Ҳ���ʶ�㰡��\n";

	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "��Ĺ��")
       	if(myfam["generation"] == 4)
            {
            	if(me->query("class")==!"taoist")
            	{
            		obn=new("/d/gumu/obj/yfzhen");
            		obn->move(me);
            		add("yfzhen", -1);
            		return "��Щ�������͸���ɡ�\n";
            	}
            	else
            	{
            		command("say ������ʦ��ĵ��ӣ��Ҹ���Ҫ���㣿.\n");
            		return 0;
            	}
        }
        else
        {
        	return 0;
        }
}	
string ask_job()
{
        object ob,feng;
object killer;
int k;
        mapping fam;

        string what;
        string *wanted;

        ob = this_player();


        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "��Ĺ��")
                return RANK_D->query_respect(this_player()) +
                "�뱾�ɺ��޹ϸ𣬲���Ϊ�����°���";

        if (ob->query("combat_exp")< 5000)  
            {
                      message_vision("$N����$nҡ��ҡͷ˵����Ŀǰ�ı��²�����׽�������˵ġ�\n", this_object(), ob);
                return ("����ȥѧ�书�ɣ�");    
            }

        if ((int)ob->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵���㲻�Ǹոշ�������������?\n", this_object(), ob);
                return ("������б���£���Ҳû�а취����");    
            }

if (ob->query("combat_exp") >1000000)
{
        if ( ob->query_temp("gumukill") )
        {
                command("say �Ҳ��Ǹ����������к���Ů����");
                return ("ȥ��һ�����ڸ�ʲô�ɣ�");    
        }
}
        if ( ob->query_temp("gmjob") )
        {
                command("say �Ҳ��ǲŽ���ȥ����佬����");
                return ("������б���£���Ҳû�а취����");    
        }

        ob->set_temp("gmjob",1);
feng=new(__DIR__"jobyufeng",1);
feng->move("/d/gumu/shulin"+(random(9)+1));
        message_vision(HIW"С��Ů��$N˵��С������������һЩ������䡣\n"NOR, ob);
        message_vision(HIW"С��Ů����һЦ��$N˵����ȥ��Ĺǰ���С����׽���۷������\n"NOR, ob);
//if (1)
if (random(30)==1)
{
ob->set_temp("gumukill",1);
        message_vision(HIR"��˵С�������в�����ݵĺ���Ů�ӣ����ҪС��һ�㡣\n"NOR, ob);
killer=new(__DIR__"killer",1);
if ((int)ob->query_skill("force",1) > 10)
{
k=(int)ob->query_skill("force",1);
}
else k=10;
        killer->move("/d/gumu/shulin"+(random(9)+1));
        killer->set("combat_exp",ob->query("combat_exp"));
        killer->set("qi", ob->query("max_qi"));
        killer->set("eff_qi", ob->query("max_qi"));
        killer->set("max_qi", ob->query("max_qi"));
        killer->set("jing", ob->query("max_jing"));
        killer->set("eff_jing", ob->query("max_jing"));
        killer->set("max_jing", ob->query("max_jing"));
        killer->set("neili", ob->query("max_neili"));
        killer->set("max_neili", ob->query("max_neili"));
killer->set_skill("strike", k*4/5);
killer->set_skill("whip", k*4/5);
        killer->set_skill("xue-dao", k*4/5);
        killer->set_skill("unarmed",k*4/5);
        killer->set_skill("xianglong-zhang",k*4/5);
        killer->set_skill("dodge", k*4/5);
        killer->set_skill("blade", k*4/5);
        killer->set_skill("parry", k*4/5);
        killer->set_skill("dashou-yin", k*4/5);
        killer->set_skill("shenkong-xing", k*4/5);
        killer->set_skill("longxiang", k*4/5);
        killer->set_skill("huntian-qigong", k*4/5);
killer->set_skill("chilian-shenzhang", k*4/5);
killer->set_skill("jueqing-bian", k*4/5);
killer->set_name(HIB "����Ů��" NOR, ({ ob->query("id")+"-heiyi nvzi"}));
ob->set_temp("gumukill",1);
}
        return (HIW"Ȼ��ȥ������佬������ҳ԰ɣ�\n"NOR);
}
int ask_fail()
{
        object me = this_player();
if (me->query("jing") < 50)
            	{
            		command("say ��ľ���̫���ˣ���һ������!.\n");
            		return 1;
            	}
if (me->query("qi") < 50)
            	{
            		command("say ��ľ���̫���ˣ���һ������!.\n");
            		return 1;
            	}
        
        if (me->query_temp("gmjob") == 1) {
                command("sigh");
                command("say ��ʵ�ڲ���ȥ�Ļ�����ֻ���ұ��˰�æ��");
me->delete_temp("gumukill");
me->delete_temp("gmjob");
me->add("jing",-me->query("max_jing")/20);
me->add("eff_jing",-me->query("max_jing")/20);
me->add("qi",-me->query("max_qi")/20);
me->add("eff_qi",-me->query("max_qi")/20);
                me->apply_condition("menpai_busy", 5 +
                        (int)me->query_condition("menpai_busy"));
//                me->apply_condition("menpai_busy",2+random(4));
                return 1;
                }
}

