inherit F_MASTER;
inherit NPC;
void create()
{
        set_name("������ʦ", ({ "liaoqing chanshi","liaoqing","chanshi"}) );
        set("nickname", "��Ϊ����");
        set("long", "������ʦ�Ǳ��δ�ʦ�ĵ��ӣ�����Լ��ʮ���꣬
������Ϊ��Ц�ݴ��ӡ�\n");
        set("gender", "����" );
        set("class", "bonze");
        set("attitude", "friendly");
        set("age", 34);
        set("shen_type", 1);
        set("str", 25);
        set("int", 28);
        set("con", 23);
        set("dex", 22);
        create_family("����μ�", 18, "����");

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 4000);
        set("max_jing", 4000);
        set("neili", 1400);
        set("max_neili", 11400);
        set("jiali", 50);
        set("combat_exp", 500000);
        set("score", 5000);

	set_skill("force", 120);
	set_skill("dodge", 180);
	set_skill("parry", 120);
	set_skill("finger", 185);
	set_skill("sword", 120);
        set_skill("sun-finger", 100);
	set_skill("tiannan-step", 180);
	set_skill("kurong-changong", 120);
	set_skill("duanjia-sword", 120);
	set_skill("six-finger", 180);
	set_skill("buddhism", 100);
	set_skill("literate", 80);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "six-finger");
	map_skill("finger", "six-finger");
	map_skill("sword", "duanjia-sword");
	prepare_skill("finger","six-finger");
        
        setup();
	carry_object("/d/xueshan/obj/b-jiasha")->wear();
	}
