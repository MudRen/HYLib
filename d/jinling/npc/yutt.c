// girl-2.c

inherit NPC;

void create()
{
	set_name("��ͤͤ", ({ "yu ting" }) );
	set("title", "����");
	set("gender", "Ů��" );
	set("age", 22);
	set("str", 12);
	set("per", 50);
	set("long", @LONG
    ����������ҹ˼�������֮�ˣ������г�������֮�ݣ�
�����߻�֮ò������........����������
LONG
);
	set("combat_exp", 1000);
	set("attitude", "friendly");

        set("chat_chance_combat", 25);
        set("chat_msg_combat", ({
"�񽿽�΢΢����һЦ�����Ѿ����ߵ��ˣ�\n",
	}) );

	set_skill("literate", 80);
//        set_skill("music", 100)

	set("inquiry", ([
		"name" : "�Ҿ����񽿽�����",
		"here": "��Ҫ���ҵ�һ����",
		"��һ��": "�������ƽ�",
		"��ҹ": "СŮ�Ӳ�����",
		"sex": "�Բ���СŮ�Ӳ�����",
	]) );

	setup();
	
	carry_object(__DIR__"obj/pink_cloth")->wear();
//   carry_object(__DIR__"obj/silk_bra")->wear();
       carry_object(__DIR__"obj/pipa")->wield();
// carry_object(__DIR__"obj/color_pants")->wear();
}

int recognize_apprentice(object ob)
{
        if( !ob->query("marks/�񽿽�") ) {
                say("�񽿽������ף��Ҳ��ǵ�����......\n");
                return 0;
        }
        return 1;
}

int accept_object(object who, object ob)
{
	if( ob->value()<1 ){
 	        command("say �Բ������е��ۣ�����Ϣ�ˣ�");
               return 0;
              } 
       if( ob->value()<50000) {
	        command("say �Բ����ҽ���̫���ˣ�");
               return 0;
              }
       if( this_player()->query("str") < 20) {
               command("chat �����˸���Ϸ�ҵ�����������");
               return 0;
              }
        
	 command("say �ҿ�ʼ���ˡ�\n");
        say("   �񽿽�������˫�ۣ���������ĵ����������� \n");
        say("�������񽿽���������������ƽ�����ˣ����Ѿ����������뵽��һ��\n");
        say("   һ�������������������һ�з��ա�\n    ������һ���µľ��硣\n"); 
        this_player()->receive_heal("gin",80); 
        this_player()->receive_heal("kee",80); 
        this_player()->receive_heal("sen",80); 
        return 1;
}

int accept_fight(object me)
{
	command("chat ����ѽ��ɱ��������������");
	return 0;
}

