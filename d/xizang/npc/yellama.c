 inherit NPC;
void smart_fight();
void smart_attack();  
void create()
{
       set_name("����", ({ "yun song", "song" }) );
       set("nickname", "��������");
        set("gender", "����" );
        set("age", 32);
        set("int", 30);
        set("class","lama");
        create_family("������", 21, "����");
        set("long",
        "�������Ǹ��׸�ɮ�Ĺ���С���ӣ��������ڡ�������֮Ϊ����\n"
        "�ڵ��Ӱ�����\n"
                );
        set("chat_chance", 1);
        set("reward_npc", 1);
        set("difficulty", 2);
        set("chat_msg", ({
                "����̾�˿����������ɴ�ʦ�֣���֪��������ô���ˡ���\n",
        }) ); 
        set("inquiry", ([
                "������": "��....������һ������ʦ�����ɵ��ߵġ�\n",
                "����": "�����ڲ��������ǵĴ������",
        ]) );
        set("attitude", "peaceful");
        set("mana",4000);
        set("max_mana",4000);
        

        set_skill("staff", 100);

        set_skill("unarmed", 100);
        set_skill("lamaism", 10);

        set_skill("force", 100);

        set_skill("spells",100);
        set_skill("parry",100);

        
        set("combat_exp", 1500000);
        

        setup();
        carry_object(__DIR__"obj/redclothh")->wear();
        carry_object(__DIR__"obj/7staff")->wield();
}   
