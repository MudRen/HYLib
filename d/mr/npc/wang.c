// /u/beyond/mr/npc/wang.c ������
// this is made by beyond
// update 1997.6.29
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_job1();
void create()
{
	set_name("������",({"wang furen","wang","furen"}));
	set("gender", "Ů��");
	set("rank_info/respect", "����");
        set("title","��٢��ɽׯ��");
  	set("long", 
              "��������٢��ɽׯ�����ˣ�������ȥ������ʮ�мӣ��������ȴ档\n");
        set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 30);
	set("int", 22);
	set("con", 28);
        set("per", 30);
	set("dex", 30);
	
	set("max_qi", 29500);
	set("max_jing", 29500);
	set("neili", 45000);
	set("max_neili", 45000);
	set("jiali", 0);
	set("combat_exp", 0500000);
	set("score", 15000);

        set_skill("xingyi-zhang",320);
        set_skill("strike",200);
        set_skill("finger",200);
        set_skill("dodge",200);
        set_skill("force", 200);
	set_skill("canhe-zhi", 320);
	set_skill("murong-jianfa",320);       
        set_skill("shenyuan-gong", 320);
	set_skill("yanling-shenfa", 320);
        set_skill("douzhuan-xingyi", 320);
	set_skill("parry", 210);
	set_skill("sword", 200);
	set_skill("literate", 200);
        set_skill("murong-daofa", 320);
        set_skill("blade",200);
        
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-jianfa");

	prepare_skill("finger","canhe-zhi");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "parry.xingyi" :),
                (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "sword.kuangjian" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.qixing" :),
                (: perform_action, "dodge.yanling" :),                
   
        }));
                set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("����Ľ��",1,"����");
        
	setup();
        carry_object(__DIR__"obj/shoe")->wear();
        carry_object(__DIR__"obj/red_silk")->wear();
        carry_object(__DIR__"obj/skirt")->wear();
	carry_object("/clone/weapon/changjian")->wield();        
        set("inquiry", ([
            "name" : "�Ҿ�����٢��ɽׯ�����ˣ��������ѵ�û��ʲô��ʾ��\n",
            "here" : "��������٢��ɽׯ��ׯԺ֮���ڣ��˴���Ϊ�ƽ�¥��\n",
            "rumors" : "������Ǳ���Ľ�ݲ����������ˡ�\n",
            "������" : "�������ҵı���Ů������ɱ�����������⡣\n",
            "Ľ�ݸ�" : "Ľ�ݸ������ǲ�������ֶ�����������Ա�֮����ʩ����ľ��������𽭺���\n",
            "������" : "������������٢��ɽׯ�Ĳ���֮����һ�����Ǳ����ȥ�ˡ�\n",
            "��٢��ɽׯ" : "���������٢��ɽׯ���Ҿ�����������ˡ�\n",
            "��ʩˮ��" : "���������������֮���ڣ�������ʩˮ��Ĳ����������Ƕ�Ķ�ѽ��\n",       
                       "����" : (: ask_job1 :),
                       "����" : "��ȥ��������Ҫ�ɣ�", 
                       "work" : (: ask_job1 :),
                       "tools" : "��ȥ��������Ҫ�ɣ�", 

       ]));
}
void init()
{
        object me, ob;
        ::init();
        ob = this_player();
        me = this_object();
 
       add_action("do_task","task"); 
     
}

string ask_job1()
{
        object me;
        object ob;
        string target;
        mapping fam;
        ob=this_player();
        me=this_object();
        fam = ob->query("family");
        
        if(!fam || fam["family_name"] != "����Ľ��")
         return ("����ȥ�����ʺ���\n");
        if (ob->query_temp("mr_job"))
         return ("�㲻���Ѿ����˹����𣿻�����ȥ����\n");
        if ( (int)ob->query_condition("mr_job" ) > 0 )
                return RANK_D->query_respect(ob) + 
                "���ս������Ȼ�������";
         ob->set_temp("mr_job","����");
         ob->apply_condition("mr_job", 4);
         return "�����˺ܶ໨�����пյĻ�������ȥ��һ�°ɡ�";
}

int do_task(string arg)
{
        int pot,exp,shen,money;
        object ob,me;
        ob=this_player();
        me=this_object();


        if(!(arg||arg=="ok")) return 0;
        if(!ob->query_temp("mr_job")) 
            return notify_fail(HIC"�Ҳ��ǵ�����ȥ�������°���\n"NOR);
        if(!ob->query_temp("mark/����")) 
            return notify_fail(CYN"������˵�������Ȱѹ��߻��������裬���������ɡ�\n"NOR);
        if(!(ob->query_temp("mark/����")))
            return notify_fail(CYN"������˵��������������? \n"NOR);
        if( arg=="ok"&& (ob->query_temp("mark/����")))
        {
          command("smile "+ob->query("id"));
          command("say "+RANK_D->query_respect(ob)+"лл�㰡��");

        money =random((int)(ob->query_skill("shenyuan-gong",1)/10))+1;
        pot =30+random(40);
        exp =40+random(60);
        shen =random(10)+30;
        if (money > 15) money=15;
        me->add_money("silver",money);
        command("give "+ob->query("id")+" "+ money +" silver");
        ob->add("potential",pot);
        ob->add("combat_exp",exp);
        ob->add("shen",shen);
        tell_object(ob,HIW" �㱻�����ˣ�\n" + 
            chinese_number(exp) + "��ʵս����\n"+
            chinese_number(pot) + "��Ǳ��\n"+
            chinese_number(shen)+ "��\n"NOR);
        ob->delete_temp("mr_job");
        ob->delete_temp("mark");        
        return 1;
        }
        return 1;
}

