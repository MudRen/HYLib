
inherit NPC;

void create()
{
       set_name("ˮ������", ({ "chaifang guanshi", "guanshi" }) );
       set("gender", "����" );
       set("age", 50);
       set("long",
               "����������ݵ�һ��С�ܼң�ר��ˮ����Ĵ�С���£�\n");
       set("combat_exp", 2500);
       set("attitude", "friendly");
              set("inquiry", ([
             "��ˮ" : "�����������ʵʵ��ˮ�����������еĸף���ͱ����ȥ������",
	       
       ]) );
       setup();

}
