#include <ansi.h>
inherit NPC;

void create()
{
        set_name("Ҷ��",({"yexiang","ye"}));
        set("title",HIR"�����"NOR);
        set("long","
Ҷ�豾�Ǹ���Ӣ���ܼ�ǿ���ˣ�ȫ�����ž������ű��˵ķ�â���ͺ���
һ��ĥ��ѩ���ĵ��������ڣ��������⣬��Ӣ�������ϵļ����ѽ����ɳۡ�
�����´����۾��ѱ�ð����޹⣬���ӿ�ʼ����͹���������������˻��
������\n");
        
        set("gender","����");
        set("group","khlr");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",8500000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
                "����":         "���ϴ����ζ���õ�����ֵĵ�����\n",
                "С��":         (: message_vision(CYN"Ҷ������ƺ��ֺ���һ�ڣ�����¶��ʹ��֮ɫ��\n"NOR,this_object()) :),
           ]));
        
        set("death_msg",CYN"\n$N��������������ֻ��һ�Σ�����˾�������������ÿ����һ��
�ж����ٻ�����ô��һ�λ���ġ������㣬�Ȼ�������ʱ��ǧ��ĪҪ�������\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance",1);
        set("chat_msg",({
                "Ҷ���Ц��������Ҳ��֪��Ϊ��ʲô����ֻ�Ǻ�Ȼ���ú�ƣ�룬ƣ���ʲô��
������ȥ�������ָо���Ҳ���ᶮ�ġ���\n",
                "����ȻЦ��Ц���������ϴ󻹿����Һ������ľ��Ѿ���ܶԵ������ˣ���ʵ��
��������������ֻ������򡣡�\n",
                "Ҷ�����ÿ���ˣ������Լ������ˣ�������˶����������˵İڲ���ֻ�к���
���ܷ������ܸı��Լ������ˣ���ֻ�����Լ�Ϊʲô���������ˡ���\n",
                "Ҷ��˵������Ҫ��ס���ϲ���ɱ�����ģ���\n",
        }) );                   
        
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
 
}      
