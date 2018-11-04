// yiweng.c ��һ��

inherit NPC;

 
void consider();

void create()
{
	set_name("��һ��", ({ "fan yiweng","fan","yiweng" }) );
	set("gender", "����" );
	set("age", 68);
	set("long", "���³���Ʈ���������΢��С��\n");
	set("attitude", "peaceful");
        set("nickname", "�����");
        set("str", 28);
	set("con", 21);
	set("int", 20);
	set("dex", 25);
 

	set("max_qi", 1500);
	set("max_jing", 1800);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 100);
	set("shen", 5000);
	set("startroom","/d/xiangyang/cross2");

	 
	set("combat_exp", 550000);

	set_skill("force", 100); 
	set_skill("finger", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("shenyuan-gong", 100);
	set_skill("literate", 80);
	set_skill("murong-daofa", 100); 
	set_skill("yanling-shenfa", 100);
        set_skill("canhe-zhi", 100);
        set_skill("blade",100);

        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "murong-daofa");
	 
        prepare_skill("finger","canhe-zhi");
	 
        set("chat_chance", 20);
	set("chat_msg", ({
	"����������Ц��:����ɽһ�߹����첻�µز��µ������ͷ���죬Ҳ�Ų������� \n",
         (: random_move :)
	}) );

	setup();
        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/d/city/obj/cloth")->wear();
//        add_money("gold", 3);
}
 

