// du.h for fight and apprentice to 3-du

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	string name, new_name;

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) )
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎麽跑到我这儿来了，哈哈哈 !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query_temp("3du-ok")==1)
		{
			ob->delete_temp("3du-ok");
	
			if (ob->query_skill("dodge",1)>=120 &&
			ob->query_skill("force",1)>=120 &&
			ob->query_skill("parry",1)>=120 &&
			ob->query_skill("buddhism",1)>=120)
			{
			command("say 你能过金刚伏魔圈，哈哈哈 !");
			command("say 贫僧又得一可塑之才，真是可喜可贺 !");

			name = ob->query("name");
			new_name = "玄" + name[2..3];
			ob->set("name", new_name);
	
			command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为少林派玄字辈弟子 !");
			command("recruit " + ob->query("id"));
			}
			else
			command("say 贫僧要收的是有用之才，你还是回去向你师父学习吧!");
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "，没能过金刚伏魔圈，我不想收你。");
			return;
		}
	}
	return;
}

