#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("�״�",({"yi dajing","yi","dajing"}));
        set("title","���־���");
        set("long","һ������Т�������ˡ����޵ú����ġ��������ϵ�ֽ��ֽ��ֽ�����£������˻��۾��ﻹ����
�ᡣ\n");
        set("gender","����");
        set("age",32);
                
        set("int",22);
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
        set("combat_exp",4000000);  
        set("attitude", "friendly");
        
        
        set("death_msg",CYN"\n$N�ں޵�˵�����ҵĽ��������ǡ������εá���̫������������\n"NOR);          
         

        set("chat_chance",1);
        set("chat_msg",({
//              "����Ц���еص�����Ů���ü�����ϴ����ԽϴԽ����ġ���\n",
        }) );                   
         
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
}
