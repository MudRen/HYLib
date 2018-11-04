// qiao-feng.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("�Ƿ�", ({"qiao feng", "feng", "qiao"}));
	set("nickname", "���Ƿ�");
	set("gender", "����");
	set("age", 29);
	set("long", 
"������ؤ���ʮ�ΰ������ڽ��������������Ľ�ݸ�����Ϊ�����Ƿ壬��Ľ�ݡ���
����һ����ͨ�Ĵֲ����ӣ�������һ���������һϵ��������������࣬���
ʮ�ֿ��࣬����һ�������ֿ���ʮ�����Ի������ӣ�˫Ŀ��磬��������\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 10);
	
	set("str", 330);
	set("int", 24);
	set("con", 330);
	set("dex", 324);

        set("qi", 132500);
	set("max_qi", 132500);
	set("jing", 133800);
	set("max_jing", 133800);
	set("neili", 333000);
	set("max_neili", 333000);
	set("jiali", 300);
	
	set("combat_exp", 9000000);
	set("score", 200000);
	set("shen", 100000);
	 
		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 250);             // �����ڹ�
	set_skill("huntian-qigong", 380);    // ��������
	set_skill("unarmed", 300);           // ����ȭ��
	set_skill("xianglong-zhang", 380);   // ����ʮ����
	set_skill("dodge", 200);      	     // ��������
	set_skill("xiaoyaoyou", 380);        // ��ң��
	set_skill("parry", 300);             // �����м�
	set_skill("staff", 300);             // ��������
	set_skill("dagou-bang", 380);        // �򹷰���
	set_skill("begging", 200);           // �л�����
	set_skill("checking", 300);          // ����;˵
	set_skill("training", 300);         // Ԧ����
	
	set_skill("yuejia-qiang", 380);        // �򹷰���
	set_skill("suohou-gong", 380);        // �򹷰���
set_skill("chansi-shou", 380);        // �򹷰���
set_skill("claw", 380);        // �򹷰���
set_skill("hand", 380);        // �򹷰���	
set_skill("club", 380);        // �򹷰���		
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
	map_skill("strike", "xianglong-zhang");
map_skill("claw", "suohou-gong");
map_skill("hand", "chansi-shou");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield lvyv bang") :),
                (: command("wield lvyv bang") :),
                (: perform_action, "unarmed.mielong" :),
                (: perform_action, "unarmed.mielong" :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.gjtq" :),     
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);



	set("book_count", 1);
	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", HIR"����"NOR);
	set("party/level", 10);
	create_family("ؤ��", 10, "����");

	setup();
	
	carry_object(__DIR__"obj/lvyv_bang");
	carry_object(__DIR__"obj/cloth")->wear();
//      carry_object(BOOK_DIR"stick_book")->wear();
}

void init()
{
 	object ob; 
	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_qiecuo","qiecuo");
}


void greeting(object me)
{
       	mapping myfam;
	myfam = (mapping)me->query("family");
	if((myfam["family_name"] == "ؤ��")&&(!me->query_skill("huntian-qigong",1))&&(me->query("combat_exp")>500000))
        {
                command("say �㾹�ҷ��������ķ��������������ȥ�ɣ�");
                command("expell " + me->query("id"));
        }
        
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20)
	{
		command("say ���л�����Ҫ�ܳԿ����ͣ����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ��л��ӣ�");
		return;
	}
	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "ؤ��")
	{
		command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α����������أ�");
		return;
	}


	if ((int)ob->query_skill("huntian-qigong",1) < 180)
	{
		command("say ��Ļ���������Ϊ������\n");
		return;
	}

	if ((int)ob->query_skill("xianglong-zhang",1) < 180)
	{
		command("say ��Ľ���ʮ������Ϊ������\n");
		return;
	}
	
	if ((int)ob->query_skill("dagou-bang",1) < 180)
	{
		command("say ��Ĵ򹷰���Ϊ������\n");
		return;
	}
	
	command("recruit "+ob->query("id"));
}



