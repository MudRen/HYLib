 // girl.c
inherit NPC; 
void create()
{
    set_name("С޲", ({ "xiao yi" }) );
    set("gender", "Ů��" );
    set("per",30);
    set("age", 18);
        set("long",
        "��λС������Ц������к�������ÿλ���ˡ�\n");
    set("combat_exp", 500000);
        set("attitude", "friendly");
    set("rank_info/respect", "С����");
        setup();
    carry_object("/clone/misc/cloth")->wear();
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
            say( "С޲Ц�����˵������λ" + RANK_D->query_respect(ob)
                + "�������漸�ѣ����ɷ��ɰɡ�\n");
                        break;
                case 1:
            say( "С޲˵������λ" + RANK_D->query_respect(ob)
                + "�������һ���ܺ�������Ԫ��\n");
                        break;
                case 2:
            say( "С޲˵������λ" + RANK_D->query_respect(ob)
                + "������������ܺã������������ġ�\n");
                   break;
        }
}     
