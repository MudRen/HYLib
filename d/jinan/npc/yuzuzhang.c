 // garrison.c
#include <ansi.h> 
inherit NPC;
void create()
{
    set_name("���䳤", ({ "yuzu zhang", "yu zu zhang" }) );
    set("long",
            "������С����Ҳ��Ҫ�����ǵ����ǣ�����������֯��һȺ�ˡ�\n");
    
    set("attitude", "heroism");
    set("str", 27);
    set("cor", 26);
    set("cps", 25);
    set("combat_exp", random(10000));
    
    set_skill("unarmed", 70+random(50));
    set_skill("staff", 70+random(50));
    set_skill("parry", 70+random(50));
    set_skill("dodge", 70+random(50));
    set_skill("move", 100+random(50));
    
    set_temp("apply/attack", 70);
    set_temp("apply/dodge", 70);
    set_temp("apply/parry", 70);
    set_temp("apply/damage", random(100));
    set_temp("apply/armor", 70);
    set_temp("apply/move", 100);
    set("chat_chance", 1);
    set("chat_msg", ({
"���䳤����������������������������Ӵ�ƺȡ���\n",
    }) );
    setup(); 
    carry_object("/clone/misc/cloth")->wear();
} 
void destory_this()
{
        message_vision("$N���ͷ���������û������Ǿ�������ɣ�������ٽ��ҡ���\n",this_object());
        message_vision("$N��Ȼ�����ȥ�� \n",this_object());
        destruct(this_object());
        return;
} 
void release_player(object player)
{
        message_vision("$N˵�������ȥ���ٺ١�����\n",this_object());
        message_vision("$N��������û�ˣ�������$n˵��������Ǯ�Ϳ��Է����ȥ���㸶�����𣿡� \n",this_object(),player);
        message_vision("$N����һ�����ƣ�������������������ƽ�50������ֱ�Ӵ����ʻ���ת��Ը��Ը�⣿(ACCEPT YES/NO)��  \n",this_object());
        add_action("do_accept","accept");
        call_out("destory_this",20);
}
int do_accept(string arg)
{
        object player;
        int amount;
        player = this_player();
        remove_call_out("destory_this");
        if (arg == "yes")
        {
                amount = player->query("deposit");
                if (amount < 500000)
                {
                        message_vision("$N�����ܻ���$n����������Ҳ���ˣ������������û��ô��Ǯ����ˣ�ң���������������ɣ��� \n",this_object(),player);
                        message_vision("$N��Ȼ�����ȥ�� \n",this_object());
                        destruct(this_object());
                }else
                {
                        amount = amount - 500000;
                        player->set("deposit",amount);
                        message_vision("$N�����ֺõ�Ц��$n˵�����Ҿ�˵��λ"+ RANK_D->query_respect(player) + "�Ǵ����ˣ������ߡ���\n",this_object(),player);
                        message_vision("$N��$n������η��� \n",this_object(),player);
                        player->move("/d/jinan/dayu");
                        player->set("vendetta/authority", 0);
                        player->delete("marks/crime");
                        message_vision("$N�����˺۵ĳ����η��� \n",player);
                        destruct(this_object());
                }
                return 1;
        }
        if (arg == "no")
        {
           message_vision("$N��ߵ���������ҪǮ��Ҫ���ļһ������������ŵ���ʱ���� \n",this_object(),player);
                message_vision("$N��Ȼ�����ȥ�� \n",this_object());
                destruct(this_object());
                return 1;
        }
        return notify_fail("��ֻ��ACCEPT YES OR NO \n");
}    
