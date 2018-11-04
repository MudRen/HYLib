// longnv.c С��Ů

// 1998.9 by Lgg

#include <ansi.h>

inherit NPC;

string ask_yunv();
string ask_me();
string ask_shoutao();
string ask_suo();
string ask_zhen();

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
        set("str", 30);
        set("int", 37);
        set("con", 36);
        set("dex", 38);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                "С��Ů���ĵص�������֪����������������п����Ҵ��������ϵ��֣���\n", 
                "С��Ů�૵�������Ů����ȫ�潣�ϱڣ��ǿ������޵С�����...����ȥ����һ�����أ���\n",
                "С��Ů�����̾�˿�����ת��ͷȥ��\n",
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
                (: perform_action, "unarmed.youju" :),
                (: perform_action, "unarmed.wuqing" :),
        }));

        set("qi", 6500);
        set("max_qi", 6500);
        set("jing", 6600);
        set("max_jing", 6600);
        set("neili", 14000);
        set("max_neili", 24000);
        set("jiali", 200);

        set("combat_exp", 2000000);
        set("score", 0);

        set_skill("force", 150);
        set_skill("throwing", 300);
        set_skill("whip", 260);
        set_skill("yinsuo-jinling", 260);
        set_skill("yangyanshu", 300);
        set_skill("yunv-xinfa", 250);    //��Ů�ķ�
        set_skill("sword", 150);
        set_skill("yunv-jian", 250);     //��Ů��
        set_skill("quanzhen-jian",130);  //ȫ�潣
        set_skill("dodge", 160);
        set_skill("yunv-shenfa", 260);   //��Ů��
        set_skill("parry", 150);
        set_skill("hubo", 120);          //˫�ֻ���
        set_skill("unarmed",150);
        set_skill("meinv-quan", 260);    //��Ůȭ��
        set_skill("literate",120);
        set_skill("qufeng",250);         //����֮��
        set_skill("wuzhan-mei",150);
        set_skill("strike",200);
        set_skill("tianluo-diwang",300);         //����֮��

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
	"������":(: ask_suo :),
	"��˿����":(: ask_shoutao :),
	"�����":(: ask_zhen :),
        ]) );

        set("env/wimpy", 40);
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
