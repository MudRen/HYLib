#include <ansi.h>
#include <command.h>
inherit NPC; 
void throw_away(object ob); 
void create()
{ 
        set_name(YEL"��������"NOR,({"tianmei"}));
        set("title","�������");
        set("gender", "Ů��" );
        set("long", "
����������ħ��ǰ���������������˵�Ů��������ǰ�����������࣬��������ʨ
һ���ѽ̳��ߣ��������ġ����������л�����й�һ����Ե��������Ů��лС��\n"); 
        set("age",20);
        set("combat_exp", 7500000);
        //set("class","swordsman");               
        set("attitude","friendly");
  set("reward_npc", 1);
       set("difficulty", 20);
       set("no_busy", 9);
       set("ill_boss",5);
              set_skill("move", 100);
    set_skill("parry",100);
    set_skill("dodge", 100);
    set_skill("force", 80);
    set_skill("literate", 120);
    set_skill("blade", 100);
    set_skill("unarmed",100);
    set_skill("demon-steps",80);
    set_skill("demon-strike",80);
    set_skill("demon-blade",120);
    set_skill("demon-force",120);
    map_skill("parry", "demon-blade");
    map_skill("blade", "demon-blade");
    map_skill("dodge", "demon-steps");
    map_skill("force", "demon-force");
    map_skill("unarmed", "demon-strike");


        set("max_atman", 600);
        set("atman", 600);
        set("max_mana", 600);
        set("mana", 600);
        set("max_neili",1500);
        set("neili",1500);
        set("force_factor",120); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
//      set("death_msg",CYN"\n$N  ��  ��    ��    �  ǻ�۱ݱݱݣۣۣ� \n"NOR);         
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);    
          set("chat_msg_combat", ({
        (: perform_action, "unarmed.dimo" :),
            (: perform_action, "dodge.lianhuanbabu" :),
            (: perform_action, "unarmed.dimo" :),

            }) );             
       // auto_npc_setup();("wang",300,200,0,"/obj/weapon/","fighter_w","shadowsteps+dabei",2);
                
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
} 

void init() {
        
        object ob;
        ::init();
        if( interactive(ob = this_player())) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        object *inv;
        string my_position;
        if( !ob || environment(ob) != environment()) return;
        if (ob->query("learn_tianmei"))  
        {
        command("hmm");
        command("say ʮ������Ψһ�ܿ��񽣵��书���������������Ӧ�������ֲ���");
        return;
        }
        if (ob->query("m_killer/л����")) 
        {
        command("ack");
        command("say ��λӢ�۾���ɱ��л�����Ǹ������ˣ����Ǵ�����ġ�����");
        command("sigh");
        ob->set("learn_tianmei",1);
        }
} 
void throw_away(object ob) {
        if( !ob || environment(ob) != environment() ||is_fighting(ob)) return;
        this_object()->kill_ob(ob);
        ob->kill_ob(this_object());
}       
 

int recognize_apprentice(object ob){
    if(ob->query("learn_tianmei")) {

        return 1;
    } else {
        if (random(2))
        message_vision("$Nҡ��ҡͷ�������δ������������\n", 
                        this_object());
        else 
        message_vision("$N������Ƭ�̣���ȴ��ȻĬ����������\n", 
                        this_object(), ob);             
                return 0;
    }
} 
