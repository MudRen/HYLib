inherit NPC;
#include <ansi.h>

void create()
{
	set_name("����ͨ", ({ "wu santong", "wu", "santong" }));
	set("title",  "��������ܹ�" );
        set("gender", "����");
              set("nickname", HIY "���Ը���" NOR );     
        set("long", 
        "�����ǵ��������Ĵ��ܹܡ�һ�ƴ�ʦ���£��������Ը����е���λ����
Ϊ�˾���ͷţ��һ���ʯѹ�����ϣ���֪˭������������help����\n");
        set("age", 45);
        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 30);
        
        set("max_qi", 11500);
        set("max_jing", 11500);
        set("neili", 11000);
        set("max_neili", 11000);
        set("jiali", 100);
        set("combat_exp", 1500000);
        set("score", 200000);
        set("inquiry", ([
                "һ�ƴ�ʦ"   : "ʦ�������˼������档\n",
                "������"     : "������ʦ�����������䡣\n",
                "������"     : "������ʦ�����������ӡ�\n",
        ]) );
        set_skill("force", 180);
        set_skill("dodge", 120);
        set_skill("parry", 180);
        set_skill("cuff", 175);
        set_skill("sword", 120);
        set_skill("staff", 120);
        set_skill("kurong-changong", 120);
        set_skill("tiannan-step", 120);
        set_skill("jinyu-quan", 125);
        set_skill("duanjia-sword", 170);
        set_skill("literate", 120);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-step");
        map_skill("sword", "duanjia-sword");
        map_skill("staff", "duanjia-sword");
        map_skill("parry", "duanjia-sword");
        map_skill("cuff", "jinyu-quan");
        prepare_skill("cuff", "jinyu-quan");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 100);


        set("combat_exp", 5000);
        set("shen_type", 1);

        
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
        add_action("do_help", "help");
}
int do_help(string arg)
{
      object me=this_player();
        if( !arg ) return notify_fail("��Ҫ����˭�ء�\n");
       if (arg=="nong fu" || arg=="fu")
          {
              if (me->query("neili")>500)
                  {
                     me->add("neili",-500);
                     me->set_temp("help_nongfu",1);                 
         message_vision("$N����ǰ����ũ������ʯ��\n", me);  
         message_vision("ũ���������һ�����ģ��������ˡ�\n", me);       
                   } 
           else 
                command("say ����˹���Ҳ�������ˡ���ȥ���������");
         }
        return 1;
}



        