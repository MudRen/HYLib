//shiren.c copy
//diabio(����)2003.4.3
inherit NPC;
inherit F_MASTER;
void away();
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

string *name_3 = ({
"����","��ӥ","�ٶ�","��ȭ","����","��Ӱ","����","����",
"����","ѪӰ","��ɱ","���","����"
});

string *weapon = ({
"changjian","hammer","tiezhang","changbian","zhubang","changqiang","qimeigun","gangdao"
});

void create()
{
	set_name(name_1[random(sizeof(name_1))] + name_2[random(sizeof(name_2))], ({"xun jing", "jing", "xun"}));
	set("gender", "����");
	set("age", 26);
	set("title", "��������");
	set("long", 
		"���������Ĵ������죬���Ծ�����������㡣\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 15);
	set("con", 20);
	set("dex", 25);
	set("bac", 15);

	set("qi", 300);
	set("max_qi", 300);
	set("jingli", 100);
       set("jiali", 100);
	
	set("combat_exp", 10000);
	
	set_skill("force", 100);
	set_skill("aikido", 100);
	set_skill("unarmed",100);
	set_skill("dodge", 100);  
        set_skill("blade", 100); 
	set_skill("shayi-xinfa", 100); 
	set_skill("wuxing-dun", 100); 
	set_skill("parry", 100); 
	set_skill("literate", 100); 
	
	setup();

        carry_object(__DIR__"obj/wushidao")->wield();

            set("chat_chance", 50);
	set("chat_msg", ({
             "Ѳ�������ȵ�������ʵ�зϵ���κ��˶���������Ͻ֣���\n",
                       (: random_move :)          
	}));
        add_money("silver", 30+random(30));
}
