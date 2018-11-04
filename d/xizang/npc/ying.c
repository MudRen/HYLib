#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("��ӥ", ({ "ying" }) );
        set("gender", "����" );
        set("long",
                "أӥ������ۣ������İ��£���������ᣬɽ������򶨡�\n" );
        set("title", GRN"��ԭ֮ӥ"NOR);
        set("attitude", "peaceful");
        set("age", 44);
        set("str", 100);
        set("cor", 36);
        set("agi", 30);
        set("per", 20);
        set("combat_exp", 10000000);
        set("max_jing",16000);
        set("max_jing",16000);
        set("max_qi",16000);
        set("neili",16000);
        set("max_neili",16000);
        set_temp("apply/damage",50);
        set("chat_chance", 1);
        set("chat_msg", ({
                "��ӥ��һ�ּ�ڽ��Ŀ������ض����㡣\n",
                }) );
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 300);
        set_skill("blade", 200);

        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("literate", 300);
	set_skill("sword", 300);
	set_skill("unarmed",380);
	set_skill("changquan",300);
	set_skill("feixian-steps",300);
	set_skill("feixian-sword",390);
	set_skill("jingyiforce",300);
        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );
           set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);             
        setup();
   carry_object("/clone/master/obj/bsword")->wield();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/guskin");
   carry_object(__DIR__"obj/roundblade1");
        add_money("gold", 1);
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_continue","continue");
} 
void greeting(object ob)
{
        object npc;
        npc = this_object();
        if( !ob || environment(ob) != environment() ) return;
        if( ob->query("score") > 5000 && ob->query_temp("marks/guanwai_knowsecret") )
        {
                message_vision("$N���˿ڹų��գ��������ֳ�һ˿Ц�⣬�������裺\n�����������������������������\n",npc);
                message_vision("$Nת��ͷ�����˿�$nЦ��������ȥ����continue .....�� \n",npc,ob);
                set("enable_continue",1);
        }
        else
        {
                message_vision("$N���˿ڹų��գ���һ�ּ�ڽ��Ŀ������ض���$n��\n",npc,ob);
        }
} 
int do_continue(string arg)
{       
        object npc,player;
        npc = this_object();
        player = this_player();
        
        if(!query("enable_continue")) return 0;
        if ( !arg )
                return notify_fail("��Ҫ������ʲô��\n");
        if (arg == "���̸���������ԡ�����" || arg == "���̸������" || arg == "���̸�����ԡ�" )
        {
                delete("enable_continue");
                message_vision("$N����Ӧ���ͳ������̸���������ԡ�������\n",player);
                call_out("ask_help",3,npc,player);
        }
        else
                message_vision("$N����ɤ�Ӻ��ҳ�����"+arg+"��\n",player);
        return 1;
} 
void ask_help(object npc,object player)
{
        object sword;
        message_vision("$N������Ц�����úã���һ�������ԣ����������Ҹ�æ���ҵ�С����\n�����ħ�۽�����������������Ϲ�����ˡ�\n",npc);
        sword = new(__DIR__"obj/magicsword");
        sword->set("owner",player->query("id"));
        sword->move(player);
        message_vision("$N�ó�һ��ħ�۽�����$n��\n",npc,player);
        player->delete_temp("marks/guanwai_knowsecret");
        player->set_temp("marks/guanwai_help_ying",1);
        return;
}      
