// Ů����

inherit NPC;
string *names = ({"��","ڤ","Ӱ","��","ظ","��","��","��","��",});
void create()
{
	set_name(names[random(sizeof(names))]+"��", ({ "dizi","nv dizi" }) );

	set("gender", "Ů��");
	set("age", 15+random(10));
	

	set("long","�����ִ���,���в�������,���Բ�Ϊ��֪��\n");
	create_family("������", 4, "����");
        set("chat_chance", 8);
        set("chat_msg", ({
                "��˵ʦ������ʱ���ڸ������еõ���һ�ѱ���,��֪��ʲô��!\n",
                (: random_move :), 
                "Сʦ�ò�֪���ֶ㵽��ȥ��,�������Ҳ���.\n",
                (: random_move :), 
                "�⼸���������˴�����,ʦ�������Ƕ������!\n",
                (: random_move :) 
        }) );

	set_skill("unarmed", 150);
	set_skill("force", 150);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	
	set_skill("sword", 150);
		set_temp("apply/attack",220);
	set_temp("apply/defense",220);
	set_temp("apply/armor",220);
	set("max_neili",500+random(5550));
	set("max_jing",500+random(5550));
		set("max_qi",500+random(5550));	

	
	set("combat_exp",50000);
	set("mingwang",1000);
	
	set("inquiry", ([
		"here" : "������Ǻ��ϰ�����ѽ,���Ȼ��֪��ô?",
	"��������":"��ʦ����,�����ھ���,Ҳ������!",
	]) );	

	setup();
	carry_object("/d/hainan/obj/shaqun")->wear();
       carry_object("/d/hainan/obj/roujing_sword")->wield();
            add_money("silver",5);
}
