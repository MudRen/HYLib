//shiren.c copy
//diabio(����)2003.4.3
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

string *name_3 = ({
"����","��ӥ","�ٶ�","��ȭ","����","��Ӱ","����","����",
"����","ѪӰ","��ɱ","���","����"
});

string *weapon = ({
"changjian","hammer","tiezhang","changbian","zhubang","changqiang","qimeigun","gangdao"
});

void create()
{
	set_name(name_1[random(sizeof(name_1))] + name_2[random(sizeof(name_2))], ({"bai xing", "bai", "xing"}));
	set("gender", "����");
	set("age", 26);
	set("long", 
		"��ͨ�İ�������ò�ĳ�����Ц��\n");
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
	
	set("combat_exp", 1000);
	
	setup();
            carry_object(__DIR__"obj/shoes")->wear();
           carry_object(__DIR__"obj/hefu")->wear();
	set("chat_chance", 10);
	set("chat_msg", ({
                                         "������ò�ĳ�����˸��к�����\n",
                        (: random_move :)          
                                     
	}));
        add_money("silver", 10+random(30));
}
