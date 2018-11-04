// npc dizi.c ����
// diabio(����)2003.3.5

inherit NPC;
inherit F_MASTER;

string *name_1 = ({
"ɽ��","����","����","��","����","����","��֥","��","��Ұ","ɽ��",
"��ľ","�ڲ�","С��","����","����","ǳ��","����","��ĩ","����","���",
"����","����","����",
});

string *name_2 = ({
"̫��","����","����","����","����","ʮһ��","ʮ����","��ʮ��","����",
"����","Ӣ��","ұ��","����","����","���","��һ","Ӣ��","��ʯ","�弪",
"һҶ","�ӹ�","����","����","��԰","��ˮ","���","���","Т��","ï",
"��","��","����","����","����","ɽ��","�ζ�",
});

void create()
{
	set_name(name_1[random(sizeof(name_1))] + name_2[random(sizeof(name_2))], ({"di zi", "zhong", "dizi"}));
	set("gender", "����");
	set("age", 26);
	set("title", "����Ż�������������");
	set("long", 
		"��Ż������ĵ��ӣ�����Ц�����Ŀ����㡣\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 15);
	set("con", 20);
	set("dex", 25);
	set("bac", 15);

	set("qi", 300);
	set("max_qi", 300);
	set("jingli", 200);
	set("max_jingli", 200);
	set("neili", 100);
	set("max_neili", 100);
       set("jiali", 30);
	
	set("combat_exp", 8000);
	
	set_skill("force", 20);
	set_skill("aikido", 20);
	set_skill("unarmed",20);
	set_skill("dodge", 20);  
        set_skill("blade", 20); 
	set_skill("shayi-xinfa", 20); 
	set_skill("wuxing-dun", 20); 
	set_skill("parry", 20); 
	set_skill("literate", 20); 
	
	setup();
	set("chat_chance", 5);
	set("chat_msg", ({
              "���������ӵ���Ϊʲô��������ô�û�û������˵�еİε�ի�أ�\n",
	}));
        add_money("silver", 10+random(30));
}

