// duanzc.c ������

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_save();
string ask_duan();
string fenglu();

void create()
{
	set_name("������", ({ "duan zhengchun", "duan" }));
	set("title",  "����������" );
	set("long", "�����Ǵ�������������������̫�ܣ��������İ���ʥ�֡�\n");
	set("gender", "����");
	set("age", 45);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 50);
	set("int", 50);
	set("con", 55);
	set("dex", 50);
	
	set("max_qi", 12500);
	set("max_jing", 11220);
	set("neili", 35000);
	set("max_neili", 35000);
	set("jiali", 100);
	set("combat_exp", 7000000);
	set("score", 300000);

        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 150);
        set_skill("cuff", 200);
        set_skill("strike", 150);
        set_skill("sword", 200);
        set_skill("staff", 150);
        set_skill("finger", 220);
        set_skill("finger", 280);
	set_skill("kurong-changong", 301);
        set_skill("tiannan-step", 280);
        set_skill("jinyu-quan", 280);
        set_skill("wuluo-zhang", 280);
        set_skill("duanjia-sword", 380);
        set_skill("yiyang-zhi", 280);
//        set_skill("sun-finger", 100);
	set_skill("literate", 200);
	set_skill("wuluo-zhang", 200);
	set_skill("feifeng-whip", 300);
	map_skill("unarmed", "yiyang-zhi");
	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "yiyang-zhi");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "yiyang-zhi");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "finger.sandie" :),
                (: perform_action, "finger.dian" :),
                (: perform_action, "finger.jian" :),
                (: perform_action, "finger.qian" :),
                (: perform_action, "finger.sandie" :),
                (: perform_action, "sword.fenglei" :),
                (: perform_action, "sword.jingtian" :),
                (: perform_action, "sword.feilong" :),   
                	(: perform_action, "sword.ailao" :),
                		(: perform_action, "sword.xswy" :) ,            
                (: perform_action, "dodge.huadie" :),
                
                (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );
        set("inquiry", ([
            "����" : (: ask_duan :),
            "name": "���������Ҿ��Ƕ��������ѵ����������������ĺ��ӣ�",
            "here": "�����������������",
            "������" : "���������Ҷμ���ѧ�����֮�أ���������������¿ɲ�����ô���׵�.",
            "Ӫ��" : (: ask_save :),
            "���" : (: ask_save :),
            "ٺ»" :  (: fenglu :),
        ]));
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
	setup();
        carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);

	create_family("����μ�",18,"������");
}

void attempt_apprentice(object ob)
{
	string oldtitle;
	oldtitle = ob->query("title");
	if ((int)ob->query_skill("kurong-changong",1) < 100 )
	{
		command("say ��ı����ڹ��ķ�̫���ˣ�����ŬŬ�������һ�°ɡ�");
		return;
	}
	if ((int)ob->query("shen") < 10000  ) {
		command("say �Ҵ�����������������壬����ذɣ�");
		return;
	}
	oldtitle = ob->query("title");
	if (strsrch(oldtitle, "������������") >= 0) 
	{
		command("say �ܺã���Ȼ���������͵�����Ϊ����");
		command("recruit " + ob->query("id"));
		ob ->set("title", oldtitle);
	}
	else
	{
		command("say ���Ǻ��ˣ���˴󵨣���ð�Ҹ������ͣ�");
		return;
	}
}
string ask_save()
{
        object ob;
        int i,j;
        i=random(5)+2;
        j=random(4)+3;
        ob=this_player();
        if ((int)ob->query("shen") < 0) 
           return ("�ҿ�" + RANK_D->query_respect(ob) +"�����а֮�����������Ĵ����һ��ļ�ϸ��");
        if ((int)ob->query("combat_exp") < 400000) 
           return ("�Ĵ���˶��Ǿ�������,"+RANK_D->query_respect(ob) +"�ƺ��书���������Ĵ�����භ��������֮�ǡ�");        
        if (ob->query_temp("duanyu/find2")) 
           return ("����ô������ȥ��?ʱ����ȣ�");                               
        if( ob->query_temp("duanyu/ask")){
           ob->set_temp("duanyu/step",-i);
           ob->set_temp("duanyu/steps",j);
           ob->set_temp("duanyu/find2",1);  
           return ("��Ȼ"+ RANK_D->query_respect(ob) +"���������������绢�������ҵ�֪���������Ĵ����֮��\n"+
                   "������������������ɽ������һ��ʯ���ڣ�ֻ��·��ʮ���ն�֮ǰΪ��̽��·�ߣ�\n"+
                   "������ʧ�ü������¡�����ȥ������ȥ����ɽ·�ϵ�һ��СϪ����������\n"+
                   "��������"+chinese_number(j)+"�������"+chinese_number(i)+"�Ȼ��ᵽһ����ɽ���������Ҫ���������ˡ�\n"+
                   "������˵�������ˣ�׼��һ�£�Ϊ�˲������Է����м�Ҫ�������ж���·��С�ġ�");
        }
        else return ("�˻��Ӻ�̸��");
}

string fenglu()
{
        object ob=this_player();
        mapping fam = ob->query("family");
        int gold;       
        if ( !fam || fam["family_name"] != "����μ�")
           return "��λ"+ RANK_D->query_respect(ob) +"�����Ҵ�����ĳ����ѵ�Ҳ�����ô����ٺ»��";
        if ( fam["master_name"] == "������")
           return "��λ"+ RANK_D->query_respect(ob) +"�ڴ���ʱ�仹̫�̣��ȹ���ʱ������ðɡ�";
if (ob->query("age") < 18)
           return "��λ"+ RANK_D->query_respect(ob) +"����̫���ˣ��ȳ��������������!";
        if (ob->query("fenglu") && ob->query("fenglu") >= ob->query("age"))
           return "��λ"+RANK_D->query_respect(ob) +"���겻���Ѿ��ù�ٺ»�ˣ���ô�������ã�";        
         ob->set("fenglu",ob->query("age"));         
         command ("pat " + ob->query("id"));         
         message_vision(NOR"����������$NһЩ"HIY"�ƽ�"NOR"��\n"NOR,ob);
         gold=(int)(ob->query_skill("kurong-changong",1)*25000);
         MONEY_D->pay_player(this_player(), gold);
         return "������һ���ٺ»����λ"+ RANK_D->query_respect(ob) +"�úøɰ���";         
}
string ask_duan()
{
        object ob = this_player();
        if( ob->query("dali/meet_dy1") && ob->query("dali/pass")){
           if( ob->query("family") && ob->query("family/family_name") =="����μ�"){
              ob->set_temp("duanyu/find4",1);
              return ("С����ǰ���岻�ʣ������常������ȥ�������ˡ�");
           }
           else return ("�ϴζ��"+RANK_D->query_respect(ob) +"��ȣ�����С��ҵ�ѿ��������Ƕ�л"+RANK_D->query_respect(ob) +"�ˡ�");
        }
        if( ob->query("dali/fail") > 6)
            return("��λ"+RANK_D->query_respect(ob) +"�������ˣ���л"+RANK_D->query_respect(ob) +"�����������ҿ����ǻ��������԰ɡ�");
        if( ob->query_temp("duanyu/find1")){
            ob->set_temp("duanyu/ask",1);
            return ("С����ǰ���Ĵ���˵��Ϻ�����°���ˣ����������跨Ӫ��������������汣��! ");
        }
        else return ("С������ѧ�䣬���ҳ��˼������ҳ����ˣ����������Ų��Ұ�! ");
}
