
inherit NPC;

void create()
{
        set_name( "�ʺ�" , ({ "queen"}));
        set("shen_type", 0);
        set("age",19);
        set("gender", "Ů��");
        set("per",28);
        set("long",
                "����һ��ݺ���Ƶ������������������ü��ӳ���Ǻ����ӵ��۾���\n"+
"���ǳ������㣬�����߻�����ɫ����Ϊ����ʵ۾��д�飬����\n"+
"����Ц�����棬��ɷ����\n");
        set("combat_exp", 800);
        set("attitude", "friendly");
        set("inquiry", ([
        ]));
      
  setup();
//        carry_object("/clone/misc/pink_cloth")->wear();
}



