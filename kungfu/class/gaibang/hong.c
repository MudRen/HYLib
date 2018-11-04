// sample master.c code
// xiake island master.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("���߹�", ({"hong qigong", "hong", "qigong"}));
	set("nickname", "��ָ��ؤ");
	set("gender", "����");
	set("age", 75);
set("beggarlvl",9);
	set("long", 
		"������ؤ���ʮ���ΰ������ųơ���ؤ���ĺ��߹���ү�ӡ�\n");
	set("attitude", "peaceful");
        set("class", "beggar");
	
	set("str", 60);
	set("int", 64);
	set("con", 60);
	set("dex", 64);

	set("chat_chance", 1);
	set("chat_msg", ({
		"���߹�̾�˿�����������������ʱ���ٳԵ��ض����ġ��л�������������\n",
		"���߹�˵�������׻�˵�����ڽ��ϡ��������Ͻл��ص��������ݿ�������\n",
		"���߹��૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����\n",
//		(: random_move :),
	}));
      set("inquiry", ([
              "������" : "����������������\n",
              "ؤ��" : "����������������\n",
              "����" : "�ҿ�ѽ�������µ����˶��Ȳ����ض����Ľл��������˭�����䡣\n",
              "��ʦ" : "�����ȥ�����ŵ��Ұ��ܶ��³�нš�\n",
      ]));

	set("qi", 25000);
	set("max_qi", 25000);
	set("jing", 22400);
	set("max_jing", 22400);
	set("neili", 58000);
	set("max_neili", 58000);
	set("jiali", 300);
	
	set("combat_exp", 8000000);
	set("score", 200000);
	set("shen", 100000);
	 
		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 300);             // �����ڹ�
	set_skill("huntian-qigong", 380);    // ��������
	set_skill("unarmed", 260);           // ����ȭ��
	set_skill("xianglong-zhang", 380);   // ����ʮ����
	set_skill("dodge", 260);      	     // ��������
	set_skill("xiaoyaoyou", 380);        // ��ң��
	set_skill("parry", 260);             // �����м�
	set_skill("staff", 380);             // ��������
	set_skill("dagou-bang", 380);        // �򹷰���
	set_skill("begging", 380);           // �л�����
	set_skill("checking", 380);          // ����;˵
	set_skill("training", 380);         // Ԧ����
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
	create_family("ؤ��", 17, "����");
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);

	setup();
	
    carry_object(__DIR__"obj/yuzhu_zhang")->wield();
    carry_object(__DIR__"obj/jiaohuaji");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20) {
		command("say ���л�����Ҫ�ܳԿ����ͣ����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ��л��ӣ�");
		return;
	}
//	if ((string)ob->query("family/family_name") != "" &&
//	    (string)ob->query("family/family_name") != "ؤ��") {
//		command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α��������Ͻл��أ�");
//		return;
//	}
	if (this_player()->query_temp("jiahuoji")) command("recruit " + ob->query("id"));
        else
	command("say " + RANK_D->query_respect(ob) + "��������������ֻ��ϧ�Ͻл�����û������ͽ����");
	
}

int accept_object(object who, object ob)
{
object ob_yzz,me = this_object();;
	if (ob->query("food_supply") <= 0)
		return 0;
	if ((string)ob->query("id") != "jiaohua ji") {
		command("say �Ͻл���" + (string)ob->query("name") + "ûʲô��Ȥ����");
		return 0;
	}
	if (query("food") >= max_food_capacity() - ob->query("food_supply")) {
		command("say �Ͻл����ڱ��úܡ�");
		return 0;
	}
	command("say ����������������ԵĽл���ѽ��");
	command("eat ji");
        command("say �벻����СС��ͣ���˼ȴ��ϸ���͸�������ض�һ����");
	who->set_temp("jiahuoji",1);
    	if ((string)who->query("family/family_name") == "ؤ��") {
 	if( ob_yzz = present("yuzhu zhang", me) ){
                ob_yzz->move(who);
                write("������ȸ����Ҷ����ˣ����͸�����������ɡ�");
        	return 1;
    		}

//        	who->add("combat_exp",random(100));
//        	who->add("potential",random(20));
                if(random(30) == 1 
        	&& who->query("family/family_name") == "ؤ��"
        	&& (int)who->query_skill("xianglong-zhang", 1) > 200
        	&& !who->query("xlz/hang")
)
{
        command("say ���һ�����ߣ��ҳ�������º���˵...");
               		call_out("kanglong", 10, who, this_object()); 
}
        	return 1;
}

	return 1;
}
int kanglong(object me, object ob)
{
	if(!ob || !me || !living(ob) || !living(me)
	|| environment(ob) != environment(me) 
	|| ob->is_fighting() || me->is_fighting())
	        return 0;
	        
        command("consider");
        command("say �����������ǲ������������ͻ�Ѿͷͬ���õ���ζ����");
        command("say ��Ҳ���ܰ׳�����Ĳˣ������ɡ�");
        command("say ��ȥ����"+YEL+"��ɳɽ"+NOR+"ס��һ���ӣ���û���컯�Ϳ����Լ��ˡ�");
//        command("say ��ȥ����"YEL"��ɳɽ"NOR"ס��һ���ӣ���û���컯�Ϳ����Լ��ˡ�");
        me->set_temp("xlz/hang", 1);
        return 1;
}
