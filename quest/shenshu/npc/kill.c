
#include <ansi.h>
inherit NPC;
string *first_name = ({ "��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��", }); 
string *name_words = ({ "һ","��","��","��","��","��","��","��","��","ʮ", });
string *color_title = ({"[��ɱ��]ɱ��","[��ɷ��]ɱ��",});

void create()
{
 string name,weapon;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))]; 
       set_name(name, ({ "killer", "shashou", "sha shou" }));
       set("gender", "����");
       set("title", color_title[random(sizeof(color_title))]);
       set("long", "��������ɫ��װ����������һ��ڲ���ֻ¶��һ˫�۾����������䡣\n");
       set("age", random(20)+25);      
	set("str", 20+random(5));
       set("int",20+random(5));  
       set("con",20+random(5));     
       set("dex",20+random(5));
        set("vendetta/authority",1);
        set("per", 1);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 1);
	set("bellicosity", 10000);
        set("chat_chance", 99);
        set("chat_msg", ({
		(: command, "get all from corpse" :),
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                "ɱ�ֺȵ�������������Ҫ������Ҫ������\n",
                "ɱ��Ц����������齻��������������ʹ��һ��!\n",
        }) );

        set_skill("unarmed", 20+random(200));
        set_skill("sword", 20+random(200));
        set_skill("parry", 20+random(200));
        set_skill("dodge", 20+random(200));
        set_skill("move", 20+random(200));

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 20);
        set_temp("apply/damage", 20+random(80));
        set_temp("apply/move", 20);

        setup();

       carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/sword")->wield();
}
int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
		 name() + "˵���������ջ�С����Ϣȥ�ˡ�\n\n",environment(),
		this_object() );
       	destruct(this_object());
}


