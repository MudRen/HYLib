//shiren.c copy
//diabio(����)2003.4.3
#include <ansi.h>
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
	set_name(name_1[random(sizeof(name_1))] + name_2[random(sizeof(name_2))], ({"wo kou", "wokou", "kou"}));
	set("gender", "����");
	set("age", 26);
	set("title", HIR"��������"NOR);
	set("long", 
		"���ϵĺ������ܣ�������������Ŀ����㡣\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 15);
	set("con", 20);
	set("dex", 25);
//       set("bac", 15);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jingli", 1000);
	set("max_jingli", 2000);
	set("neili", 2000);
	set("max_neili", 2000);
       set("jiali", 40);
	
	set("combat_exp", 10000);
	
	set_skill("force", 100);
	set_skill("aikido", 100);
	set_skill("unarmed",100);
	set_skill("dodge", 100);  
        set_skill("blade", 100); 
	set_skill("shayi-xinfa", 100); 
	set_skill("wuxing-dun", 100); 
	set_skill("parry", 100); 
	set_skill("wuxing-dun", 100); 
	set_skill("aikido", 100); 
	set_skill("shayi-xinfa", 100); 
	set_skill("feitian-yujianliu", 100); 
        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
              map_skill("unarmed", "aikido");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "feitian-yujianliu");	
	set("chat_chance", 20);
	set("chat_msg", ({
              "�������ܺȵ���ɱ��ɱ��ɱ��ȫ������ɱ����\n",
	}));
	
	setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/wushidao")->wield();

        add_money("silver", 30+random(30));
}
void init()
{
        remove_call_out("leave");
        call_out("leave",50);
}
void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "����һ������������ܲ����ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
